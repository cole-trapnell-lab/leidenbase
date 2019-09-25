#
# This file is a lightly modified copy of the Gabor Csardi's
# R igraph Makevars.in file.
# R igraph is distributed under the GPL-2+ license.
# We acknowledge Gabor Csardi's work on the R/C igraph
# distributions and for making the source code publicly
# and freely available.
#
CXX_STD=CXX11
PKG_CFLAGS=-I. \
        -Icigraph/src  \
        -Icigraph/include \
        -Icigraph/src/cs  \
        -Icigraph/src/glpk \
        -Icigraph/src/plfit \
        -Icigraph/src/CHOLMOD/Include \
        -Icigraph/src/AMD/Include \
        -Icigraph/src/COLAMD/Include   \
	-Icigraph/src/SuiteSparse_config \
	@CPPFLAGS@ @CFLAGS@ -DNDEBUG -DNPARTITION -DNTIMER -DNCAMD -DNPRINT\
	-DPACKAGE_VERSION=\"@VERSION_IGRAPH@\" -DINTERNAL_ARPACK \
	-DIGRAPH_THREAD_LOCAL=/**/
PKG_CXXFLAGS= -DIGRAPH_THREAD_LOCAL=/**/ -DNDEBUG \
        -I. \
        -Icigraph/src \
        -Icigraph/include \
        -Icigraph/src/prpack \
        -Ileidenalg/include \
        -DPRPACK_IGRAPH_SUPPORT
PKG_LIBS=@XML2_LIBS@ @GMP_LIBS@ @GLPK_LIBS@ $(FLIBS) $(LAPACK_LIBS) $(BLAS_LIBS)

all: $(SHLIB)


