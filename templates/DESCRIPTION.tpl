Package: leidenbase
Type: Package
Title: R and C wrappers to run the Leiden find_partition function
Version: @VERSION_LEIDENBASE@
Authors@R: person( 'Brent', 'Ewing', role = c( 'aut', 'cre' ), email = 'bge@uw.edu' )
Description: An R to C interface that runs the Leiden community
    detection algorithm to find a basic partition. It runs the
    equivalent of the find_partition() function, which is
    given in the Leidenalg distribution file
    'leiden/src/functions.py'. This package includes the
    required source code files from the official Leidenalg
    distribution and several functions from the R igraph
    package.  The Leidenalg distribution is available from
    https://github.com/vtraag/leidenalg
    and the R igraph package is available from
    https://igraph.org/r/.
    The Leiden algorithm is described in the article
    'From Louvain to Leiden: guaranteeing well-connected communities',
    V. A. Traag and L. Waltman and N. J. van Eck,
    Scientific Reports (2019),
    DOI: 10.1038/s41598-019-41695-z.
Requires: R (>= 3.0.0)
Imports:
    igraph (>= 0.8.2)
License: GPL (>=2) + file LICENSE
Encoding: UTF-8
LazyData: true
RoxygenNote: 6.1.1
Suggests: 
    testthat
