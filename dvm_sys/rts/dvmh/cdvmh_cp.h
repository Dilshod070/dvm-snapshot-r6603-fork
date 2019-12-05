#pragma once

#include <cstdio>
#include <string>
#include <sstream>

#include "dvmh_async.h"

// #include "dvmh_stdio.cpp" // TODO: do not include this
namespace libdvmh {
enum RWKind { rwkRead, rwkWrite }; // TODO: get original from cdmh_stdio.cpp
enum DvmhCpMode {LOCAL, PARALLEL, LOCAL_ASYNC, PARALLEL_ASYNC};

class ControlPoint {

  public:
    //    typedef std::vector Vector;
    typedef std::string String;
    typedef std::vector<size_t> VectorSize;
    typedef std::vector<String> VectorStr;
    typedef std::vector<DvmType *> VectorDesc;

  public:
    static const std::string DIRNAME;
    static std::string NumberToString(int number) {
        std::ostringstream stream;
        stream << number;
        return stream.str();
    }

  public:
    String directory;
    String name;
    VectorDesc varDescList;
    VectorSize varSizeList;
    VectorSize varNmembList;

    int axesNum;
    VectorSize axesSizeList;

    DvmhCpMode mode;
    int nfiles;
    int nextfile;

  public:
    ControlPoint() {}
    ControlPoint(String name, VectorDesc varlist, int nfiles, DvmhCpMode mode);
    ControlPoint(String name, VectorDesc varlist);

  public:
    int getFilesNum() const { return nfiles; }
    int getNextFile() const { return nextfile; }
    int getLastFile() const { return (this->getNextFile() - 1) % this->getFilesNum(); }
    void incFileQueue() { nextfile = (this->getNextFile() + 1) % this->getFilesNum(); }
    void decFileQueue() { nextfile = (this->getNextFile() - 1) % this->getFilesNum(); }

    String getNextFilename() const {
        if (this->mode == LOCAL) {
            return directory + "/" + ControlPoint::NumberToString(this->getNextFile()) + "_" + "%d" + ".txt";
        } else if (this->mode == PARALLEL){
            return directory + "/" + ControlPoint::NumberToString(this->getNextFile()) + ".txt";
        } else {
            exit(1);
        }
    }
    String getLastFilename() const {
        if (this->mode == LOCAL) {
            return directory + "/" + ControlPoint::NumberToString(this->getLastFile()) + "_" + "%d" + ".txt";
        } else if (this->mode == PARALLEL){
            return directory + "/" + ControlPoint::NumberToString(this->getLastFile()) + ".txt";
        } else {
            exit(1);
        }
    }
    String getHeaderFilename() const {
        if (this->mode == LOCAL) {
            return this->directory + "/Header" + "_" + "%d" + ".txt";
        } else if (this->mode == PARALLEL){
            return this->directory + "/Header" + ".txt";
        } else {
            exit(1);
        }
    }

    String getOpenMode(const String &rw, bool async=false, bool binary=true) const {
        String res = rw;
        if (binary) { res += "b"; }
        if (async) { res += "s"; }
        if (this->mode == LOCAL) {
            res += "l";
        } else if (this->mode == PARALLEL){
            res += "p";
        } else {
            exit(1);
        }
        return res;
    }

}; // class ControlPoint

const std::string ControlPoint::DIRNAME = "./control_points";

}; // namespace libdvmh
