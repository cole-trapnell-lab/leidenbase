#
# This file is a lightly modified copy of the Gabor Csardi's
# R igraph Makevars.win file.
# R igraph is distributed under the GPL-2+ license.
# We acknowledge Gabor Csardi's work on the R/C igraph
# distributions and for making the source code publicly
# and freely available.
#

LIB_XML ?= $(MINGW_PREFIX)
GLPK_HOME ?= $(MINGW_PREFIX)
LIB_GMP ?= $(MINGW_PREFIX)

PKG_CPPFLAGS= -DUSING_R \
              -DHAVE_FMEMOPEN=0 \
              -DHAVE_OPEN_MEMSTREAM=0 \
              -DHAVE_RINTF \
              -DWin32 \
              -DHAVE_UNISTD_H \
              -Wall \
              -DHAVE_FMIN=1 \
              -DHAVE_LOG2=1 \
              -DHAVE_SNPRINTF \
              -DHAVE_GFORTRAN \
              -DIGRAPH_THREAD_LOCAL= \
              -DPRPACK_IGRAPH_SUPPORT \
              -Ileidenalg/include \
              -Irigraph/src \
              -Irigraph/src/include \
              -Irigraph/src/cs \
              -Irigraph/src/plfit \
              -Irigraph/src/prpack \
              -Irigraph/src/SuiteSparse_config \
              -I${GLPK_HOME}/include \
              -DNDEBUG \
              -DNPARTITION \
              -DNTIMER \
              -DNCAMD \
              -DNPRINT \
              -I${LIB_GMP}/include \
              -DINTERNAL_SUITESPARSE \
              -DINTERNAL_ARPACK \
              @XML2_CPPFLAGS@

PKG_LIBS = @XML2_LIBS@ -liconv -lz -lws2_32 @GLPK_LIBS@ $(BLAS_LIBS) $(LAPACK_LIBS) -lgfortran -lquadmath @GMP_LIBS@

all: $(SHLIB)


