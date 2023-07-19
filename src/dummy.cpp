/*
** A source code file placed in leidenbase/src to mollify CRAN checks.
**
** This file serves two purposes:
**   o  it precludes complaints about missing source code files in the
**      src directory
**   o  it causes the CRAN checker to link with the C++ standard
**      libraries
*/

#include <iostream.h>

int a_dummy_function_cpp(void)
{
  return(1);
}
