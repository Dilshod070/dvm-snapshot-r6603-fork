.KEEP_STATE:
#############################################################################
#                                                                           #
#                                  PRESAGE                                  #
#                                                                           #
#############################################################################

EXE	= predictor
LIB	= rater
LIBDIR = ../../Rater/Src
ZLIB	= zlib
ZLIBDIR = ../../Zlib/Src
INC_DIR = -I../Include -I../../Rater/Include -I../../Zlib/Include

COPT    = -g -w $(INC_DIR) -DP_DEBUG
LINK	= $(CXX)

.SUFFIXES: .o .cpp
.cpp.o:
	$(CXX) -c $(COPT) $*.cpp

MODULES  = \
	CallParams.o \
	Event.o \
	FuncCall.o \
	Interval.o \
	IntervalTemplate.o \
	ModelDArray.o \
	ModelInterval.o \
	ModelIO.o \
	ModelMPS_AM.o \
	ModelParLoop.o \
	ModelReduct.o \
	ModelRegular.o \
	ModelShadow.o \
	ModelRemAccess.o \
	ParseString.o \
	Predictor.o \
	Processor.o \
	Ps.o \
	TraceLine.o 


################################## PREDICTOR ################################
all: $(EXE)

$(EXE): $(MODULES)
	$(CXX) -v
	$(LINK) -o $(EXE) $(MODULES) -L$(LIBDIR) -l$(LIB) -L$(ZLIBDIR) -l$(ZLIB)

############################################################################
	
clean:
	rm -f *.o $(EXE)


################################## END #####################################
