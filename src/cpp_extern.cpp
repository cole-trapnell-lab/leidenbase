#include <R_ext/Visibility.h>

extern "C" {
/* .Call calls */
extern SEXP _leiden_find_partition( SEXP igraph, SEXP partition_type, SEXP initial_membership, SEXP edge_weights, SEXP node_sizes, SEXP seed, SEXP resolution_parameter, SEXP num_iter );
}
