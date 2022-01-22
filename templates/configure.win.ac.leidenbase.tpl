dnl
dnl File: configure.ac
dnl Notes:
dnl   o  run autoconf in order to make the configure
dnl      file from this configure.ac file.
dnl   o  configure.ac is not part of the distribution.
dnl      It is used only to make the configure file,
dnl      which is part of the distribution.
dnl
dnl   o  the Makefile in the leidenbase directory of
dnl      the dev branch is not part of the distribution.
dnl      It is used only to set up the distribution.
dnl
dnl This file is based largely on Gabor Csardi's
dnl R igraph configure.ac file.
dnl R igraph is distributed under the GPL-2+ license.
dnl We acknowledge Gabor Csardi's work on the R/C igraph
dnl distributions and for making the source code publicly 
dnl and freely available.
dnl
AC_INIT([leidenbase], @VERSION@)
AC_CONFIG_SRCDIR(src/leidenFindPartition.cpp)

: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
   echo "could not determine R_HOME"
   exit 1
fi

R_BIN="${R_HOME}/bin/R"

CC=`"${R_BIN}" CMD config CC`
CXX11=`"${R_BIN}" CMD config CXX11`
CXX11STD=`"${R_BIN}" CMD config CXX11STD`
CXX="${CXX11} ${CXX11STD}"
FC=`"${R_BIN}" CMD config FC`
CPPFLAGS=`"${R_BIN}" CMD config CPPFLAGS`
CFLAGS=`"${R_BIN}" CMD config CFLAGS`
CXXFLAGS=`"${R_BIN}" CMD config CXX11FLAGS`
FCFLAGS=`"${R_BIN}" CMD config FCFLAGS`

AC_PROG_CC
AC_LANG(C)

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

dnl set up for building igraph.
dnl most of the following is from the R igraph distribution.
LIBS_SAVE=$LIBS
LIBS="$LIBS -lm"
AC_CHECK_FUNCS([rintf finite expm1 rint log2 logbl snprintf log1p round fmin stpcpy])
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
              AC_HELP_STRING([--disable-graphml], [Disable support for GraphML format]),
              [graphml_support=$enableval], [graphml_support=yes])

HAVE_LIBXML=0
if test $graphml_support = yes; then
  AC_PATH_PROG([XML2CONFIG], [xml2-config], [none])
  if test "$XML2CONFIG" = "none"; then
    graphml_support=no
  else
    XML2_LIBS=`$XML2CONFIG --libs`
    XML2_CFLAGS=`$XML2CONFIG --cflags`
    AC_CHECK_LIB([xml2], [xmlSAXUserParseFile], [
      OLDCFLAGS=${CFLAGS}
      OLDCPPFLAGS=${CPPFLAGS}
      CFLAGS=${XML2_CFLAGS}
      CPPFLAGS=${XML2_CFLAGS}
      AC_CHECK_HEADER([libxml/parser.h], [
        HAVE_LIBXML=1
        AC_DEFINE([HAVE_LIBXML], [1], [Define to 1 if you have the libxml2 libraries installed])
        CFLAGS="${OLDCFLAGS} ${XML2_CFLAGS}"
        CPPFLAGS="${OLDCFLAGS} ${XML2_CFLAGS}"
        AC_SUBST(XML2_LIBS)
        AC_SUBST(XML2_CFLAGS)
      ], [
        graphml_support=no
        CFLAGS=${OLDCFLAGS}
        CPPFLAGS=${OLDCPPFLAGS}
      ])
    ], [
      graphml_support=no
    ])
  fi
fi
AC_SUBST(HAVE_LIBXML)

AC_LANG_PUSH([C++])
HAVE_GMP=0
GMP_LIBS=""
gmp_support=no
AC_ARG_ENABLE(gmp, AC_HELP_STRING([--disable-gmp], [Compile without the GMP library]))
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

glpk_support=yes
AC_DEFINE([HAVE_GLPK], [1], [Define to 1 if you have the GLPK library])
HAVE_GLPK=1
GLPK_LIBS=""
AC_SUBST(HAVE_GLPK)
AC_SUBST(GLPK_LIBS)

AC_DEFINE(IGRAPH_THREAD_LOCAL, [], [We don't care about thread-local storage in R])

AC_CONFIG_SUBDIRS([src/cigraph])

dnl create output
AC_CONFIG_FILES([src/Makevars.tmp:src/Makevars.win.in], [
    if test -f src/Makevars.win && cmp -s src/Makevars.tmp src/Makevars.win; then
      AC_MSG_NOTICE([creating src/Makevars.win])
      AC_MSG_NOTICE([src/Makevars.win is unchanged])
      rm src/Makevars.tmp
    else
      AC_MSG_NOTICE([creating src/Makevars.win])
      mv src/Makevars.tmp src/Makevars.win
    fi
  ]
)
AC_OUTPUT

