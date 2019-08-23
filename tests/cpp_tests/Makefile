CXX= c++
CXXFLAGS= -g -I/usr/local/include -I. -I/usr/local/include/igraph -std=c++11
CXXLIB= -L/usr/local/lib -ligraph -lm

OBJ01= leiden.o leidenFindPartition.o \
CPMVertexPartition.o \
LinearResolutionParameterVertexPartition.o \
ModularityVertexPartition.o \
MutableVertexPartition.o \
RBConfigurationVertexPartition.o \
ResolutionParameterVertexPartition.o \
RBERVertexPartition.o \
SignificanceVertexPartition.o \
SurpriseVertexPartition.o \
GraphHelper.o Optimiser.o

all: leiden

leiden: $(OBJ01)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ01) $(CXXLIB)

clean:
	rm -f $(OBJ01) leiden

