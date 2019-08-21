#
# This file is a lightly modified copy of the Gabor Csardi's
# R igraph Makevars.win file.
# R igraph is distributed under the GPL-2+ license.
# We acknowledge Gabor Csardi's work on the R/C igraph
# distributions and for making the source code publicly
# and freely available.
#
PKG_CPPFLAGS= -I${LIB_XML}/include/libxml2 -I${LIB_XML}/include -DLIBXML_STATIC -DUSING_R -DHAVE_FMEMOPEN=0 -DHAVE_OPEN_MEMSTREAM=0 -DHAVE_RINTF -DWin32 -DHAVE_LIBXML -Wall -DPACKAGE_VERSION=\"@VERSION_IGRAPH@\" -DHAVE_FMIN=1 -DHAVE_LOG2=1 -DHAVE_SNPRINTF -Ics -Iglpk -DHAVE_GLPK=1 -Iplfit -Iprpack -DIGRAPH_THREAD_LOCAL=/**/ -DPRPACK_IGRAPH_SUPPORT -I. -Iinclude -ICHOLMOD/Include -IAMD/Include -ICOLAMD/Include -ISuiteSparse_config -DNDEBUG -DNPARTITION -DNTIMER -DNCAMD -DNPRINT -I$(LIB_GMP)/include

PKG_CFLAGS = -DINTERNAL_ARPACK -I. -I$(LIB_GMP)/include -DHAVE_GFORTRAN

PKG_LIBS = -L${LIB_XML}/lib -lxml2 -liconv -lz -lws2_32 -lgmp -L$(LIB_GMP)/lib $(BLAS_LIBS) $(LAPACK_LIBS)


