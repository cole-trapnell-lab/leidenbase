# Reporting Issues with Installing leidenbase

Please report issues with installing leidenbase using the [leidenbase issues](https://github.com/cole-trapnell-lab/leidenbase/issues/) page on github.com.and please include the following information, which may help us to understand the problem

  *  [computer system](#computer-system)
  *  [R installation](#r-installation)
  *  [R sessionInfo()](#r-sessioninfo)
  *  [describe the error](#describe-the-error)


## Computer system

I need to know the type, name, and version of your computer
system. Is it MacOS, Linux, Windows, or some other system?
Examples are

```
  Windows 10 Pro
  MacOS version 10.14
  Ubuntu Linux 18.04.3
```

In order to install leidenbase, you must have C, C++, and
FORTRAN compilers installed on your system. Please check
for them and report the names, locations, and versions of
them, if possible.

Examples are

```
  language       some compiler commands
  --------       ----------------------
  C              cc, gcc, clang
  C++            c++, g++, clang++
  FORTRAN        f77, f95, gfortran, flang
```

If you installed any of the compilers manually or using
a package manager, please include that information.


## R installation

Please report your R version and how you installed it on your
system. Did you build R manually from source code, install a
package from CRAN, or build or install from another repository
or package manager, for example, Homebrew?

If possible, please include information from the file called
'Makeconf', which is part of the R installation. This file is
found usually either in the directory or a subdirectory of
R_HOME/etc, where R_HOME is a directory path that you can find
using the R command *R.home()*.

The helpful lines in this file start with the strings

```
CC =
CFLAGS =
CPICFLAGS =
CPPFLAGS =
CXX =
CXXCPP =
CXXFLAGS =
CXXPICFLAGS =
CXX98 =
CXX98FLAGS =
CXX98PICFLAGS =
CXX98STD =
CXX11 =
CXX11FLAGS =
CXX11PICFLAGS =
CXX11STD =
CXX14 =
CXX14FLAGS =
CXX14PICFLAGS =
CXX14STD =
CXX17 =
CXX17FLAGS =
CXX17PICFLAGS =
CXX17STD =
CXX_VISIBILITY =
DYLIB_EXT =
DYLIB_LD =
DYLIB_LDFLAGS =
DYLIB_LINK =
FC =
FCFLAGS =
FCLIBS_XTRA =
FFLAGS =
FLIBS =
```

## R sessionInfo

Please report the information from the R command 'sessionInfo()'.


## Describe the error

Please report the error and post relevant output.

If possible, please include the full output of the install command, which you can get by

* download the leidenbase release as a *.tar.gz* file, which you can get from [https://github.com/cole-trapnell-lab/leidenbase/releases](https://github.com/cole-trapnell-lab/leidenbase/releases)
* in a terminal running the bash shell, go to the directory where you have the leidenbase release file
* run the following command (the release file at the time of writing is *leidenbase-0.1.0.tar.gz*, you may need to change this name if there is a more recent release)

```
R CMD INSTALL leidenbase-0.1.0.tar.gz > install.out 2>&1
```

* attach the resulting *install.out* file to your issue report


## Thank you

I appreciate your feedback and patience.

