#
# This file is a lightly modified copy of the Gabor Csardi's
# R igraph Makevars.in file.
# R igraph is distributed under the GPL-2+ license.
# We acknowledge Gabor Csardi's work on the R/C igraph
# distributions and for making the source code publicly
# and freely available.
#
CXX_STD=CXX11
PKG_CPPFLAGS=-DUSING_R \
         -Ileidenalg/include \
         -Irigraph/src \
         -Irigraph/src/include \
         -Irigraph/src/cs \
         -Irigraph/src/plfit \
         -Irigraph/src/prpack \
         -Irigraph/src/SuiteSparse_config \
         @XML2_CPPFLAGS@ -DNDEBUG -DNPARTITION -DNTIMER -DNCAMD -DNPRINT \
         -DINTERNAL_ARPACK -DPRPACK_IGRAPH_SUPPORT -DIGRAPH_THREAD_LOCAL=/**/
PKG_LIBS=@XML2_LIBS@ @GMP_LIBS@ @GLPK_LIBS@ $(FLIBS) $(LAPACK_LIBS) $(BLAS_LIBS) $(FLIBS)

ifneq (,$(filter $(DEB_HOST_ARCH),i386))
PKG_CPPFLAGS = $(PKG_CPPFLAGS) -ffloat-store
endif

all: $(SHLIB)


