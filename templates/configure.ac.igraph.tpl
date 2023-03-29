dnl This file is based largely on Gabor Csardi's
dnl R igraph configure.ac file.
dnl R igraph is distributed under the GPL-2+ license.
dnl We acknowledge Gabor Csardi's work on the R/C igraph
dnl distributions and for making the source code publicly
dnl and freely available.
dnl
AC_INIT(igraph, 1.2.11, ntamas@gmail.com)
AC_CONFIG_HEADERS(src/config.h)

: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
   echo "could not determine R_HOME"
   exit 1
fi
CC=`"${R_HOME}/bin/R" CMD config CC`
CXX=`"${R_HOME}/bin/R" CMD config CXX`
FC=`"${R_HOME}/bin/R" CMD config FC`
CFLAGS=`"${R_HOME}/bin/R" CMD config CFLAGS`
CXXFLAGS=`"${R_HOME}/bin/R" CMD config CXXFLAGS`
CPPFLAGS=`"${R_HOME}/bin/R" CMD config CPPFLAGS`
FCFLAGS=`"${R_HOME}/bin/R" CMD config FCFLAGS`
FLIBS=`"${R_HOME}/bin/R" CMD config FLIBS`
LDFLAGS=`"${R_HOME}/bin/R" CMD config LDFLAGS`

AC_LANG(C)
AC_PROG_CC

# Fortran compiler, we need to check if it is the GNU compiler
AC_PROG_FC
if test "x$ac_cv_fc_compiler_gnu" = xyes; then
  AC_DEFINE([HAVE_GFORTRAN], [1], [Define to 1 if using the GNU fortran compiler])
fi

AC_DEFINE([INTERNAL_SUITESPARSE], [1], [Define to 1 if you use the internal SuiteSparse library])

dnl Tricky check for C++ compiler, because Autoconf has a weird bug:
dnl http://lists.gnu.org/archive/html/autoconf/2006-03/msg00067.html
AC_PROG_CXX
AC_LANG_PUSH([C++])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <iostream>
const char hw[] = "Hello, World\n";]],
                [[std::cout << hw;]])],
        [AC_PROG_CXXCPP
        cxx_error=no],
        [AC_MSG_ERROR([no C++ compiler found or it cannot create executables])])
AC_LANG_POP([C++])

LIBS_SAVE=$LIBS
LIBS="$LIBS -lm"
AC_CHECK_FUNCS([rintf finite expm1 rint log2 logbl snprintf log1p round fmin stpcpy])
AC_CHECK_DECLS(isfinite,,,[#include <math.h>])
AC_CHECK_DECL([stpcpy],
    [AC_DEFINE([HAVE_STPCPY_SIGNATURE], [1], [Define to 1 if the stpcpy function has a signature])])
LIBS=$LIBS_SAVE

AC_CHECK_HEADER([sys/times.h],
    [AC_DEFINE([HAVE_TIMES_H], [1], [Define to 1 if you have the sys/times.h header])])

AC_CHECK_HEADERS([ \
           net/if.h \
           netinet/in.h \
           net/if_dl.h \
           sys/sockio.h \
           sys/un.h \
           sys/socket.h \
           sys/ioctl.h \
           sys/time.h \
           sys/file.h \
        ])

AC_CHECK_MEMBER([struct sockaddr.sa_len],
                AC_DEFINE_UNQUOTED([HAVE_SA_LEN], [1], [Define if struct sockaddr contains sa_len]), [],
        [#include <sys/types.h>
         #include <sys/socket.h>])

graphml_support=yes
AC_ARG_ENABLE(graphml,
              AS_HELP_STRING([--disable-graphml], [Disable support for GraphML format]),
              [graphml_support=$enableval], [graphml_support=yes])

HAVE_LIBXML=0
if test $graphml_support = yes; then
  AC_PATH_PROG([XML2CONFIG], [xml2-config], [none])
  if test "$XML2CONFIG" = "none"; then
    graphml_support=no
  else
    # xml2-config puts only preprocessor flags in --cflags (i.e. -D and -I) so
    # we can put them in XML2_CPPFLAGS. This might not be true for other
    # libraries, though.
    XML2_CPPFLAGS=`$XML2CONFIG --cflags`
    XML2_LIBS=`$XML2CONFIG --libs`
    OLDLIBS=${LIBS}
    LIBS=${XML2_LIBS}
    AC_CHECK_LIB([xml2], [xmlSAXUserParseFile], [
      OLDCPPFLAGS=${CPPFLAGS}
      CPPFLAGS=${XML2_CPPFLAGS}
      AC_CHECK_HEADER([libxml/parser.h], [
        HAVE_LIBXML=1
        AC_DEFINE([HAVE_LIBXML], [1], [Define to 1 if you have the libxml2 libraries installed])
      ], [
        graphml_support=no
      ])
      CPPFLAGS=${OLDCPPFLAGS}
    ], [
      graphml_support=no
    ])
    LIBS=${OLDLIBS}
  fi
fi
AC_SUBST(HAVE_LIBXML)
AC_SUBST(XML2_LIBS)
AC_SUBST(XML2_CPPFLAGS)

AC_LANG_PUSH([C++])
HAVE_GMP=0
GMP_LIBS=""
gmp_support=no
AC_ARG_ENABLE(gmp, AS_HELP_STRING([--disable-gmp], [Compile without the GMP library]))
if test "x$enable_gmp" != "xno"; then
  AC_CHECK_LIB([gmp], [__gmpz_add], [
    AC_CHECK_HEADER([gmp.h], [
      HAVE_GMP=1
      AC_DEFINE([HAVE_GMP], [1], [Define to 1 if you have the GMP library])
      gmp_support=yes
      GMP_LIBS="-lgmp"
    ])
  ])
fi
AC_SUBST(HAVE_GMP)
AC_SUBST(GMP_LIBS)
AC_LANG_POP([C++])

HAVE_GLPK=0
GLPK_LIBS=""
glpk_support=no
AC_ARG_ENABLE(glpk, AS_HELP_STRING([--disable-glpk], [Compile without the GLPK library]))
if test "x$enable_gmp" != "xno"; then
  AC_CHECK_LIB([glpk], [glp_read_mps], [
    AC_CHECK_HEADER([glpk.h], [
      AC_EGREP_CPP(yes, [
        #include <glpk.h>
        #if GLP_MAJOR_VERSION > 4 || (GLP_MAJOR_VERSION == 4 && GLP_MINOR_VERSION >= 38)
          yes
        #endif
      ], [
        HAVE_GLPK=1
        AC_DEFINE([HAVE_GLPK], [1], [Define to 1 if you have the GLPK library])
        glpk_support=yes
        GLPK_LIBS="-lglpk"
      ])
    ])
  ])
fi
AC_SUBST(HAVE_GLPK)
AC_SUBST(GLPK_LIBS)

AC_DEFINE(IGRAPH_THREAD_LOCAL, [], [We don't care about thread-local storage in R])

dnl AC_CONFIG_FILES([src/Makevars.tmp:src/Makevars.in], [
dnl     if test -f src/Makevars && cmp -s src/Makevars.tmp src/Makevars; then
dnl       AC_MSG_NOTICE([creating src/Makevars])
dnl       AC_MSG_NOTICE([src/Makevars is unchanged])
dnl       rm src/Makevars.tmp
dnl     else
dnl       AC_MSG_NOTICE([creating src/Makevars])
dnl       mv src/Makevars.tmp src/Makevars
dnl     fi
dnl   ]
dnl )

AC_OUTPUT
