Package: leidenbase
Type: Package
Title: R and C/C++ Wrappers to Run the Leiden find_partition() Function
Authors@R: c( person('Brent', 'Ewing', email = 'bge@uw.edu', role = c('aut', 'cre')),
              person('Vincent', 'Traag', role = 'ctb'),
              person('Gábor', 'Csárdi', role = 'ctb'),
              person('Tamás', 'Nepusz', role = 'ctb'),
              person('Szabolcs', 'Horvat', role = 'ctb'),
              person('Fabio', 'Zanini', role = 'ctb'))
Version: @VERSION_LEIDENBASE@
Description: An R to C/C++ interface that runs the Leiden community
    detection algorithm to find a basic partition (). It runs the
    equivalent of the 'leidenalg' find_partition() function, which is
    given in the 'leidenalg' distribution file
    'leiden/src/functions.py'. This package includes the
    required source code files from the official 'leidenalg'
    distribution and functions from the R 'igraph'
    package.  The 'leidenalg' distribution is available from
    <https://github.com/vtraag/leidenalg/>
    and the R 'igraph' package is available from
    <https://igraph.org/r/>.
    The Leiden algorithm is described in the article by
    Traag et al. (2019) <doi:10.1038/s41598-019-41695-z>.
Imports:
    igraph (>= 0.8.2)
License: GPL-3
Encoding: UTF-8
RoxygenNote: 7.1.2
Depends: R (>= 3.5.0)
Suggests:
    rmarkdown,
    knitr,
    testthat (>= 3.1.0)
URL: https://github.com/cole-trapnell-lab/leidenbase
BugReports: https://github.com/cole-trapnell-lab/leidenbase/issues
NeedsCompilation: yes
Maintainer: Brent Ewing <bge@uw.edu>
VignetteBuilder: knitr
