#
#   Leidenalg find partition R-C interface.
#   Copyright (C) 2019  Cole Trapnell <coletrap@uw.edu>
#   University of Washington, Genome Sciences Department, Seattle, WA
#
#  This file is free software: you can redistribute it and/or modify it under
#  the terms of the GNU General Public License as published by the Free Software
#  Foundation, either version 3 of the License, or (at your option) any later
#  version.
#
#  This program is distributed in the hope that it will be useful, but WITHOUT ANY
#  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
#  PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License along with
#  this program. If not, see http://www.gnu.org/licenses/.
#

#'@title Leiden find partition community detection function
#'
#'@description R to C wrapper that runs the basic Leiden community detection algorithm,
#'which is similar to the find_partition() function in the python Leidenalg distribution.
#'
#'@details
#'The Leiden algorithm is described in
#'  From Louvain to Leiden: guaranteeing well-connected communities.
#'  V. A. Traag and L. Waltman and N. J. van Eck
#'  Scientific Reports, 9(1) (2019)
#'  DOI: 10.1038/s41598-019-41695-z.
#'
#'Significance is described in
#'  Significant Scales in Community Structure
#'  V. A. Traag, G. Krings, and P. Van Dooren
#'  Scientific Reports, 3(1) (2013)
#'  DOI: 10.1038/srep02930
#'
#' Notes excerpted from leidenalg/src/VertexPartition.py
#' \itemize{
#'   \item \emph{ CPMVertexPartition }
#'         Implements Constant Potts Model. 
#'         This quality function uses a linear resolution parameter and
#'         is well-defined for both positive and negative edge weights.
#'   \item \emph{ ModularityVertexPartition }
#'         Implements modularity. 
#'         This quality function is well-defined only for positive edge weights.
#'   \item\emph{  RBConfigurationVertexPartition }
#'         Implements Reichardt and Bornholdt’s Potts model with a configuration null model. 
#'         This quality function uses a linear resolution parameter and is well-defined only
#'         for positive edge weights.
#'   \item \emph{ RBERVertexPartition }
#'         Implements Reichardt and Bornholdt’s Potts model with an Erdos-Renyi null model.
#'         This quality function uses a linear resolution parameter and is well-defined only
#'         for positive edge weights.
#'   \item \emph{ SignificanceVertexPartition }
#'         Implements Significance. 
#'         This quality function is well-defined only for unweighted graphs.
#'   \item \emph{ SurpriseVertexPartition }
#'         Implements (asymptotic) Surprise.
#'         This quality function is well-defined only for positive edge weights.
#' }
#' 
#'@param igraph R igraph graph.
#'@param partition_type String partition type name. Default is
#'  CPMVertexParition.
#'@param initial_membership Numeric vector of initial membership
#'  assignments of nodes. These are 1-based indices. Default is one
#'  community per node.
#'@param edge_weights Numeric vector of edge weights. Default is 1.0 for
#'   all edges.
#'@param node_sizes Numeric vector of node sizes. Default is 1 for all
#'  nodes.
#'@param seed Numeric random number generator seed. The seed value must be
#'  either NULL for random seed values or greater than 0 for a fixed seed
#'  value. Default is NULL.
#'@param resolution_parameter Numeric resolution parameter. The value
#'  must be greater than 0.0. Default is 0.1. The resolution_parameter is
#'  ignored for the partition_types ModularityVertexPartition,
#'  SignificanceVertexPartition, and SurpriseVertexPartition.
#'@param num_iter Numeric number of iterations. Default is 2.
#'@param verbose A logic flag to determine whether or not we should print
#'  run diagnostics.
#'
#'@return A named list consisting of a numeric vector of the node
#'  community memberships (1-based indices), a numeric quality value,
#'  a numeric modularity, a numeric significance, a numeric vector of
#'  edge weights within each community, a numeric vector of edge weights
#'  from each community, a numeric vector of edge weights to each
#'  community, and total edge weight.
#'
#'@references
#' V. A. Traag, L. Waltman, N. J. van Eck (2019). From Louvain
#'  to Leiden: guaranteeing well-connected communities.
#'  Scientific Reports, 9(1).
#'  DOI: 10.1038/s41598-019-41695-z
#' 
#'Significant Scales in Community Structure
#'  V. A. Traag, G. Krings, and P. Van Dooren
#'  Scientific Reports, 3(1) (2013)
#'  DOI: 10.1038/srep02930
#'
#' @examples
#'   library(igraph)
#'   fpath <- system.file( 'testdata', 'igraph_n1500_edgelist.txt.gz', package = 'leidenbase' )
#'   zfp <- gzfile(fpath)
#'   igraph <- read_graph( file = zfp, format='edgelist', n=1500 )
#'   res <- leiden_find_partition(igraph=igraph,
#'                                partition_type='CPMVertexPartition',
#'                                resolution_parameter=1e-5)
#'
#' @import igraph
#' @export
leiden_find_partition <- function( igraph, partition_type = c( 'CPMVertexPartition', 'ModularityVertexPartition', 'RBConfigurationVertexPartition', 'RBERVertexPartition', 'SignificanceVertexPartition', 'SurpriseVertexPartition' ), initial_membership = NULL, edge_weights = NULL, node_sizes = NULL, seed = NULL, resolution_parameter = 0.1, num_iter = 2, verbose = FALSE )
{
  partition_type <- match.arg( partition_type )
	
  # Check input parameters
  err_string = ''

  # igraph must be an igraph graph object
  stopifnot( is_igraph( igraph ) )

  # we need the vertex and edge counts to check input vector lengths
  num_edge   = igraph::gsize( igraph )
  num_vertex = igraph::gorder( igraph )

  # check input vector parameters
  if( !is.null( initial_membership ) )
  {
    if( length( initial_membership ) != num_vertex )
      err_string <- paste( err_string, '  -> initial_membership length != number of vertices\n', sep = '' )
    if( mode( initial_membership ) != 'numeric' )
      err_string <- paste( err_string, '  -> initial_membership is not an numeric vector\n', sep = '' )
  }

  if( !is.null( edge_weights ) )
  {
    if( length( edge_weights ) != num_edge )
      err_string <- paste( err_string, '  -> edge_weights length != number of edges\n', sep = '' )
    if( mode( edge_weights ) != 'numeric' )
      err_string <- paste( err_string, '  -> edge_weights is not an double vector\n', sep = '' )
  }

  if( !is.null( node_sizes ) )
  {
    if( length( node_sizes ) != num_vertex )
      err_string <- paste( err_string, '  -> node_sizes length != number of vertices\n', sep = '' )
    if( mode( node_sizes ) != 'numeric' )
      err_string <- paste( err_string, '  -> node_sizes is not an numeric vector\n', sep = '' )
  }

  # check remaining parameters
  if( !is.null( seed ) && ( mode( seed ) != 'numeric' || seed <= 0 ) )
    err_string <- paste( err_string, '  -> seed < 1\n', sep = '' )

  # Check resolution parameter if relevant.
  if( partition_type %in% c('CPMVertexPartition','RBConfigurationVertexPartition','RBERVertexPartition') )
  {
    if( is.null( resolution_parameter ) )
      resolution_parameter = 0.1
    if( mode( resolution_parameter ) != 'numeric' || resolution_parameter <= 0.0 )
      err_string <- paste( err_string, '  -> resolution_parameter <= 0\n', sep = '' )
  }

  if( is.null( num_iter ) )
	  num_iter = 2  
  if( mode( num_iter ) != 'numeric' || num_iter < 1 )
    err_string <- paste( err_string, '  -> num_iter < 1\n', sep = '' )
  if( !identical( err_string, '' ) )
    stop( paste( 'input parameter error(s):\n', err_string, sep = ''  ) )

  if( verbose )
  {
    message( 'leiden_find_partition: partition_type       ', partition_type )
    if( is.null( seed ) )
      message( 'leiden_find_partition: seed                  NULL' )
    else
      message( 'leiden_find_partition: seed                 ', seed )
    message( 'leiden_find_partition: resolution_parameter ', resolution_parameter )
    message( 'leiden_find_partition: num_iter             ', num_iter )
    message( 'leiden_find_partition: initial_membership   ', length(initial_membership ) )
    message( 'leiden_find_partition: edge_weights         ', length( edge_weights ) )
    message( 'leiden_find_partition: node_sizes           ', length( node_sizes ) )
    message( 'leiden_find_partition: number vertices      ', num_vertex )
    message( 'leiden_find_partition: number edges         ', num_edge )
  }
  
  result = .Call( '_leiden_find_partition', igraph, partition_type, initial_membership, edge_weights, node_sizes, seed, resolution_parameter, num_iter )

  return( result )
}

.onUnload <- function (libpath)
{
  library.dynam.unload("leidenbase", libpath)
}
