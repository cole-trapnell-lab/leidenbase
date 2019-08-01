AC_INIT([leidenbase], 0.1.0)
AC_CONFIG_SRCDIR([src/leidenFindPartition.cpp])

AC_REQUIRE_CPP

dnl find CXX compiler
R_HOME=`R RHOME`
if test -z "${R_HOME}"; then
  echo "could not determine R_HOME"
  exit 1
fi

CXX=`"${R_HOME}/bin/R" CMD config CXX`
CXXSTD=`"${R_HOME}/bin/R" CMD config CXXSTD`
CXX="${CXX} ${CXXSTD}"
CXXFLAGS=`"${R_HOME}/bin/R" CMD config CXXFLAGS`
AC_LANG(C++)

dnl default values for C igraph library
AC_SUBST([IGRAPH_INCLUDE], "-I/usr/local/include/igraph -I.")
AC_SUBST([IGRAPH_LIBS], "-L/usr/local/lib -ligraph")

dnl allow for override for C igraph library
AC_ARG_WITH([igraph],
            AC_HELP_STRING([--with-igraph=PATH],
                           [path to where igraph is installed [/usr/local]]),
            [
             IGRAPH_INCLUDE="-I${with_igraph}/include/igraph -I."
             IGRAPH_LIBS="-L${with_igraph}/lib -ligraph"
            ],
            [])

dnl create and report output
AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT
echo
echo "Final src/Makevars"
cat src/Makevars
echo
