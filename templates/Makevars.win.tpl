#
# This file is a lightly modified copy of the Gabor Csardi's
# R igraph Makevars.win file.
# R igraph is distributed under the GPL-2+ license.
# We acknowledge Gabor Csardi's work on the R/C igraph
# distributions and for making the source code publicly
# and freely available.
#
CXX_STD=CXX11
PKG_CPPFLAGS=-I. \
        -Icigraph/src  \
        -Icigraph/include \
        -Icigraph/src/cs  \
        -Icigraph/src/glpk \
        -Icigraph/src/plfit \
        -Icigraph/src/CHOLMOD/Include \
        -Icigraph/src/AMD/Include \
        -Icigraph/src/COLAMD/Include   \
        -Icigraph/src/SuiteSparse_config \
        -DUSING_R -DNDEBUG -DNPARTITION -DNTIMER -DNCAMD -DNPRINT\
        -DPACKAGE_VERSION=\"1.1.2.9000\" -DINTERNAL_ARPACK \
        -DIGRAPH_THREAD_LOCAL= \
        -DHAVE_GFORTRAN
PKG_CXXFLAGS= -DIGRAPH_THREAD_LOCAL= -DNDEBUG \
        -I. \
        -Icigraph/src \
        -Icigraph/include \
        -Icigraph/src/prpack \
        -Ileidenalg/include \
        -DUSING_R -DPRPACK_IGRAPH_SUPPORT
PKG_LIBS= -liconv -lz -lws2_32 -lgfortran -lquadmath $(BLAS_LIBS) $(LAPACK_LIBS) $(FLIBS)

all: $(SHLIB)


