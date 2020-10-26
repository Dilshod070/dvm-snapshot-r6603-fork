#include "converter.h"

#include "messages.h"

namespace cdvmh {

bool isGlobalC(const Decl *d) {
    const DeclContext *dc = d->getDeclContext();
    return !isa<ParmVarDecl>(d) && (dc->isTranslationUnit() || dc->isExternCContext());
}

std::string genRtType(std::string baseType) {
    std::string result;
    if (baseType == "int") {
        result = "rt_INT";
    } else if (baseType == "bool" || baseType == "_Bool") {
        result = "rt_LOGICAL";
    } else if (baseType == "long") {
        result = "rt_LONG";
    } else if (baseType == "long long") {
        result = "rt_LLONG";
    } else if (baseType == "float") {
        result = "rt_FLOAT";
    } else if (baseType == "double") {
        result = "rt_DOUBLE";
    } else if (baseType == "_Complex float") {
        result = "rt_FLOAT_COMPLEX";
    } else if (baseType == "_Complex double") {
        result = "rt_DOUBLE_COMPLEX";
    } else {
        result = "rt_UNKNOWN";
    }
    return result;
}

static std::string declToStr(Decl *d, bool removeStorage = true) {
    StorageClass prevClass;
    VarDecl *vd = llvm::dyn_cast<VarDecl>(d);
    //FunctionDecl *fd = llvm::dyn_cast<FunctionDecl>(d);
    bool hasInit = vd && vd->hasInit();
    Stmt *initSave = 0;
    if (hasInit) {
        initSave = *vd->getInitAddress();
        *vd->getInitAddress() = 0;
    }
    if (removeStorage) {
        if (vd) {
            prevClass = vd->getStorageClass();
            vd->setStorageClass(SC_None);
        }
    }
    std::string ss;
    llvm::raw_string_ostream ost(ss);
    d->print(ost);
    if (hasInit)
        *vd->getInitAddress() = initSave;
    if (removeStorage) {
        if (vd)
            vd->setStorageClass(prevClass);
    }
    return ost.str();
}

// MyDeclContext

VarDecl *MyDeclContext::lookupVar(const std::string &varName) const {
    std::map<std::string, VarDecl *>::const_iterator it = vars.find(varName);
    if (it != vars.end())
        return it->second;
    else if (parent)
        return parent->lookupVar(varName);
    else
        return 0;
}

bool MyDeclContext::add(VarDecl *vd) {
    bool res = false;
    std::string varName = vd->getName();
    std::string varFullName = vd->getQualifiedNameAsString();
    if (!varName.empty() && varName == varFullName) {
        std::map<std::string, VarDecl *>::iterator it = vars.find(varName);
        if (it != vars.end()) {
            VarDecl *def1, *def2;
            def1 = vd->getDefinition();
            def2 = it->second->getDefinition();
            checkIntErrN(def1 == def2, 91, varName.c_str(), (void *)def1, (void *)def2);
            res = vd != it->second;
        } else {
            res = true;
        }
        vars[varName] = vd;
    }
    return res;
}

// ConverterASTVisitor

ConverterASTVisitor::ConverterASTVisitor(SourceFileContext &aFileCtx, CompilerInstance &aComp, Rewriter &R): fileCtx(aFileCtx),
        projectCtx(fileCtx.getProjectCtx()), opts(projectCtx.getOptions()), comp(aComp), rewr(R), srcMgr(rewr.getSourceMgr()), langOpts(rewr.getLangOpts()) {
    indentStep = genIndent(1, fileCtx.useTabs());
    inRegion = false;
    regionStmt = 0;
    curRegion = "0";
    inParLoop = false;
    parLoopStmt = 0;
    inParLoopBody = false;
    parLoopBodyStmt = 0;
    inHostSection = false;
    hostSectionStmt = 0;
    declContexts.push_back(new MyDeclContext());
    preventExpandToDelete = false;
}

void ConverterASTVisitor::addToDeclGroup(Decl* head, Decl* what) {
    declGroups[head].push_back(what);
}

void ConverterASTVisitor::afterTraversing() {
    if (!opts.useBlank && !addedCudaFuncs.empty()) {
        for (std::set<const FunctionDecl *>::iterator it = addedCudaFuncs.begin(); it != addedCudaFuncs.end(); it++) {
            fileCtx.addToCudaHeading(std::string("static __device__ ") + declToStr(const_cast<FunctionDecl *>(*it)));
        }
    }
}

void ConverterASTVisitor::genUnbinded(FileID fileID, int line) {
    int prevPragmaLine;
    do {
        prevPragmaLine = fileCtx.getLatestPragmaLine(fileID.getHashValue());
        genActuals(fileID, line);
        genRedistributes(fileID, line);
        genRealignes(fileID, line);
        genIntervals(fileID, line);
        genShadowAdds(fileID, line);
        genLocalizes(fileID, line);
        genUnlocalizes(fileID, line);
        genArrayCopies(fileID, line);
        genCheckpoints(fileID, line);
    } while (fileCtx.getLatestPragmaLine(fileID.getHashValue()) > prevPragmaLine);
}

void ConverterASTVisitor::checkNonDvmExpr(const MyExpr &expr, DvmPragma *curPragma) {
    for (std::set<std::string>::iterator it = expr.usedNames.begin(); it != expr.usedNames.end(); it++) {
        VarDecl *vd = seekVarDecl(*it);
        if (vd) {
            checkIntErrN(varStates.find(vd) != varStates.end(), 92, vd->getNameAsString().c_str());
            VarState *varState = &varStates[vd];
            checkDirErrN(varState->isRegular, 401, expr.strExpr.c_str());
        }
    }
}

bool ConverterASTVisitor::flushToDelete(std::string &toInsert, std::string indent, int uptoLevel) {
    if (uptoLevel < 0)
        uptoLevel = (int)toDelete.size() - 1;
    bool haveSomething = false;
    for (int i = (int)toDelete.size() - 1; i >= 0 && i >= uptoLevel; i--) {
        for (int j = (int)toDelete[i].size() - 1; j >= 0; j--) {
            toInsert += indent + toDelete[i][j].first + "(" + toDelete[i][j].second + ");\n";
            haveSomething = true;
        }
    }
    return haveSomething;
}

bool ConverterASTVisitor::isFull(Stmt *s) {
    std::string str = convertToString(s);
    if (!str.empty() && str[str.size() - 1] == '\n')
        str.resize(str.size() - 1);
    if (str.empty())
        return false;
    else if (str[str.size() - 1] == '}' || str[str.size() - 1] == ';')
        return true;
    else
        return false;
}

bool ConverterASTVisitor::isCudaFriendly(FunctionDecl *f) {
    // TODO: Implement
    if (!f)
        return false;
    return f->isDefined();
}

class FuncAdder: public RecursiveASTVisitor<FuncAdder> {
public:
    FuncAdder(ConverterASTVisitor *converter): conv(converter) {}
public:
    bool VisitDeclRefExpr(DeclRefExpr *e) {
        std::string name = e->getNameInfo().getAsString();
        bool globalDecl = isGlobalC(e->getDecl());
        if (isa<FunctionDecl>(e->getDecl())) {
            if (globalDecl && !conv->projectCtx.hasCudaReplacement(name)) {
                conv->addFuncForCuda(cast<FunctionDecl>(e->getDecl()));
            }
        }
        return true;
    }
protected:
    ConverterASTVisitor *conv;
};

bool ConverterASTVisitor::addFuncForCuda(FunctionDecl *f) {
    if (!isCudaFriendly(f))
        return false;
    const FunctionDecl *def;
    f->isDefined(def);
    if (addedCudaFuncs.find(def) != addedCudaFuncs.end() || addCudaFuncs.find(def) != addCudaFuncs.end())
        return true;
    addCudaFuncs.insert(def);
    FuncAdder adder(this);
    adder.TraverseStmt(f->getBody());
    return true;
}

SourceLocation ConverterASTVisitor::escapeMacroBegin(SourceLocation loc) {
    bool ok = true;
    while (loc.isMacroID()) {
        ok = Lexer::isAtStartOfMacroExpansion(loc, srcMgr, langOpts, &loc);
        if (!ok)
            break;
    }
    if (!ok) {
        PresumedLoc ploc = srcMgr.getPresumedLoc(srcMgr.getFileLoc(loc));
        userErrN(ploc.getFilename(), ploc.getLine(), 53);
    }
    return loc;
}

SourceLocation ConverterASTVisitor::escapeMacroEnd(SourceLocation loc) {
    bool ok = true;
    while (loc.isMacroID()) {
        ok = Lexer::isAtEndOfMacroExpansion(loc, srcMgr, langOpts, &loc);
        if (!ok)
            break;
    }
    if (!ok) {
        PresumedLoc ploc = srcMgr.getPresumedLoc(srcMgr.getFileLoc(loc));
        userErrN(ploc.getFilename(), ploc.getLine(), 53);
    }
    return loc;
}

VarDecl *ConverterASTVisitor::seekVarDecl(std::string name, MyDeclContext *context) {
    if (!context) {
        checkIntErrN(!declContexts.empty(), 94);
        context = declContexts.back();
    }
    return context->lookupVar(name);
}

bool ConverterASTVisitor::VisitDecl(Decl *d) {
    SourceLocation fileLoc = srcMgr.getFileLoc(d->getLocation());
    std::string fileName = srcMgr.getFilename(fileLoc);
    FileID fileID = srcMgr.getFileID(fileLoc);
    int line = srcMgr.getLineNumber(fileID, srcMgr.getFileOffset(fileLoc));
    if (!isDeclAllowed() && !(isa<VarDecl>(d) && outerPrivates.find(cast<VarDecl>(d)) != outerPrivates.end()))
        userErrN(fileName, line, 402);
    return true;
}

VarState ConverterASTVisitor::fillVarState(VarDecl *vd) {
    SourceLocation fileLoc = srcMgr.getFileLoc(vd->getLocation());
    std::string fileName = srcMgr.getFilename(fileLoc);
    FileID fileID = srcMgr.getFileID(fileLoc);
    int line = srcMgr.getLineNumber(fileID, srcMgr.getFileOffset(fileLoc));
    std::string varName = vd->getName();
    checkIntErrN(varStates.find(vd) == varStates.end(), 95, varName.c_str(), fileName.c_str(), line);
    bool hasRestrict = vd->getType().isRestrictQualified();
    const Type *baseType = vd->getType().getUnqualifiedType().getDesugaredType(comp.getASTContext()).split().Ty;
    std::vector<MyExpr> sizes;
    if (baseType->isPointerType() || isa<IncompleteArrayType>(baseType)) {
        sizes.push_back(MyExpr());
        if (baseType->isPointerType())
            baseType = baseType->getPointeeType().getUnqualifiedType().getDesugaredType(comp.getASTContext()).split().Ty;
        else
            baseType = cast<IncompleteArrayType>(baseType)->getArrayElementTypeNoTypeQual();
        cdvmhLog(DONT_LOG, fileName, line, "Outer pointer/incomplete array type found");
    }
    while (baseType->isArrayType()) {
        //checkUserErr(baseType->getAsArrayTypeUnsafe()->getSizeModifier() == ArrayType::Normal, fileName, line,
        //        "That kind of array size modifier is not supported for variable '%s'", varName.c_str());
        MyExpr nextSize;
        if (const ConstantArrayType *ca = llvm::dyn_cast<const ConstantArrayType>(baseType)) {
            nextSize.strExpr = toStr(ca->getSize().getZExtValue());
        } else if (const VariableArrayType *va = llvm::dyn_cast<const VariableArrayType>(baseType)) {
            Expr *e = va->getSizeExpr();
            // TODO: Fill somehow info on references in this expression
            nextSize.strExpr = convertToString(e);
        } else if (const DependentSizedArrayType *dsa = llvm::dyn_cast<const DependentSizedArrayType>(baseType)) {
            nextSize.strExpr = convertToString(dsa->getSizeExpr());
        } else {
            //checkUserErr(false, fileName, line,
            //        "That kind of array type is not supported for variable '%s'", varName.c_str());
            cdvmh_log(WARNING, 52, MSG(52), baseType->getTypeClassName());
            nextSize.strExpr = "0";
        }
        sizes.push_back(nextSize);
        baseType = baseType->getArrayElementTypeNoTypeQual();
    }
    std::string typeName = QualType(baseType, 0).getAsString();
    // XXX: dirty
    if (typeName == "_Bool" && fileCtx.getInputFile().CPlusPlus)
        typeName = "bool";
    VarState varState;
    varState.init(varName, typeName, sizes);
    if (strstr(baseType->getCanonicalTypeInternal().getAsString().c_str(), "type-parameter-"))
        varState.hasDependentBaseType = true;
    if (hasRestrict)
        varState.canBeRestrict = true;
    return varState;
}

bool ConverterASTVisitor::VisitDeclStmt(DeclStmt *ds) {
    SourceLocation fileLoc = srcMgr.getFileLoc(ds->getEndLoc());
    std::string fileName = srcMgr.getFilename(fileLoc);
    FileID fileID = srcMgr.getFileID(fileLoc);
    int line = srcMgr.getLineNumber(fileID, srcMgr.getFileOffset(fileLoc));
    if (projectCtx.hasInputFile(fileName))
        cdvmhLog(TRACE, fileName, line, "DeclStmt: isSingle=%d", (int)ds->isSingleDecl());
    if (ds->isSingleDecl()) {
        addToDeclGroup(ds->getSingleDecl(), ds->getSingleDecl());
    } else {
        for (DeclGroupRef::iterator it = ds->getDeclGroup().begin(); it != ds->getDeclGroup().end(); it++)
            addToDeclGroup(*ds->getDeclGroup().begin(), *it);
    }
    return true;
}

bool ConverterASTVisitor::TraverseFunctionProtoTypeLoc(FunctionProtoTypeLoc ft) {
    SourceLocation fileLoc = srcMgr.getFileLoc(ft.getBeginLoc());
    PresumedLoc ploc = srcMgr.getPresumedLoc(fileLoc);
    cdvmhLog(DONT_LOG, ploc.getFilename(), ploc.getLine(), "Entering MyDeclContext(Function)");
    enterDeclContext(true);
    bool res = base::TraverseFunctionProtoTypeLoc(ft);
    checkIntervalBalance(fileLoc);
    leaveDeclContext();
    cdvmhLog(DONT_LOG, ploc.getFilename(), ploc.getLine(), "Leaving MyDeclContext(Function)");
    return res;
}

bool ConverterASTVisitor::VisitCompoundStmt(CompoundStmt *s) {
    if (preventExpandToDelete)
        preventExpandToDelete = false;
    else
        toDelete.resize(toDelete.size() + 1);
    enterDeclContext(true);
    if (FunctionDecl *f = findUpwards<FunctionDecl>(s, 1)) {
        for (int i = 0; i < (int)f->getNumParams(); i++)
            declContexts.back()->add(f->getParamDecl(i));
    }
    return true;
}

}
