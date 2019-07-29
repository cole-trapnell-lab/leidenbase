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
#'@details The Leiden algorithm is described in
#'From Louvain to Leiden: guaranteeing well-connected communities.
#'V. A. Traag and L. Waltman and N. J. van Eck
#'Scientific Reports (2019)
#'DOI: 10.1038/s41598-019-41695-z.
#'
#'
#' Notes from leidenalg/src/VertexPartition.py
#' \itemize{
#'   \item \emph{ CPMVertexPartition }
#'         Implements CPM. 
#'         This quality function is well-defined for both positive and negative edge weights.
#'         This quality function uses a linear resolution parameter.
#'   \item \emph{ ModularityVertexPartition }
#'         Implements modularity. 
#'         This quality function is well-defined only for positive edge weights.
#'   \item\emph{  RBConfigurationVertexPartition }
#'         Implements Reichardt and Bornholdt’s Potts model with a configuration null model. 
#'         This quality function is well-defined only for positive edge weights.
#'         This quality function uses a linear resolution parameter.
#'   \item \emph{ RBERVertexPartition }
#'         Implements Reichardt and Bornholdt’s Potts model with an Erdos-Renyi null model.
#'         This quality function is well-defined only for positive edge weights.
#'         This quality function uses a linear resolution parameter.
#'   \item \emph{ SignificanceVertexPartition }
#'         Implements Significance. 
#'         This quality function is well-defined only for unweighted graphs.
#'   \item \emph{ SurpriseVertexPartition }
#'         Implements (asymptotic) Surprise.
#'         This quality function is well-defined only for positive edge weights.
#' }
#'
#'@param igraph R igraph graph.
#'@param partition_type String partition type name.
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
#'  must be greater than 0.0. Default is 0.5.
#'@param num_iter Numeric number of iterations. Default is 2.
#'@param verbose A logic flag to determine whether or not we should print
#'  run diagnostics.
#'
#'@return A named list consisting of a numeric vector of the node
#'  memberships (1-based indices), a numeric quality value, a numeric
#'  vector of edge weights within each community, a numeric vector of
#'  edge weights from each community, a numeric vector of edge weights
#'  to each community, total edge weight, and a numeric vector of
#'  individual community modularities.
#'
#'@references V. A. Traag, L. Waltman, N. J. van Eck (2019). From Louvain
#'  to Leiden: guaranteeing well-connected communities.
#'  Scientific Reports, 9(1).
#'  doi: 10.1038/s41598-019-41695-z
#'@useDynLib leidenbase _leiden_find_partition
#'@import igraph
#'@export
leiden_find_partition <- function( igraph, partition_type = c( 'RBConfigurationVertexPartition', 'CPMVertexPartition', 'ModularityVertexPartition', 'RBERVertexPartition', 'SignificanceVertexPartition', 'SurpriseVertexPartition' ), initial_membership = NULL, edge_weights = NULL, node_sizes = NULL, seed = NULL, resolution_parameter = 0.5, num_iter = 2, verbose = FALSE )
{
	partition_type <- match.arg( partition_type )
	
  # Check input parameters
  err_string = ''

  # igraph must be an igraph graph object
  stopifnot( is_igraph( igraph ) )

  # we need the vertex and edge counts to check input vector lengths
  num_edge   = igraph::gsize( igraph )
  num_vertex = igraph::gorder( igraph )

  # check input vectors
  if( !is.null( initial_membership ) )
  {
    if( length( initial_membership ) != num_vertex )
    {
      err_string <- paste( err_string, '  -> initial_membership length != number of vertices\n', sep = '' )
    }
    if( mode( initial_membership ) != 'numeric' )
    {
      err_string <- paste( err_string, '  -> initial_membership is not an numeric vector\n', sep = '' )
    }
  }

  if( !is.null( edge_weights ) )
  {
    if( length( edge_weights ) != num_edge )
    {
      err_string <- paste( err_string, '  -> edge_weights length != number of edges\n', sep = '' )
    }
    if( mode( edge_weights ) != 'numeric' )
    {
      err_string <- paste( err_string, '  -> edge_weights is not an double vector\n', sep = '' )
    }
  }

  if( !is.null( node_sizes ) )
  {
    if( length( node_sizes ) != num_vertex )
    {
      err_string <- paste( err_string, '  -> node_sizes length != number of vertices\n', sep = '' )
    }
    if( mode( node_sizes ) != 'numeric' )
    {
      err_string <- paste( err_string, '  -> node_sizes is not an numeric vector\n', sep = '' )
    }
  }

  # check remaining parameters
  if( !is.null( seed ) && ( mode( seed ) != 'numeric' || seed <= 0 ) )
  {
    err_string <- paste( err_string, '  -> seed < 1\n', sep = '' )
  }

  if( is.null( resolution_parameter ) )
  {
    resolution_parameter = 0.5
  }
  if( mode( resolution_parameter ) != 'numeric' || resolution_parameter <= 0.0 )
  {
    err_string <- paste( err_string, '  -> resolution_parameter <= 0\n', sep = '' )
  }

  if( is.null( num_iter ) )
  {
	num_iter = 2  
  }
  if( mode( num_iter ) != 'numeric' || num_iter < 1 )
  {
    err_string <- paste( err_string, '  -> num_iter < 1\n', sep = '' )
  }

  if( !identical( err_string, '' ) )
  {
    stop( paste( 'input parameter error(s):\n', err_string, sep = ''  ) )
  }
  
  if( is.null( resolution_parameter ) || ( !is.integer( resolution_parameter ) && !is.double( resolution_parameter ) ) )
  {
	resolution_parameter = 0.5
  }
  
  if( is.null( num_iter ) || ( !is.integer( num_iter ) && !is.double( num_iter ) ) )
  {
    num_iter = 2
  }

  if( verbose )
  {
    cat( 'leiden_find_partition: partition_type       ', partition_type, '\n')
    cat( 'leiden_find_partition: seed                 ', seed, '\n')
    cat( 'leiden_find_partition: resolution_parameter ', resolution_parameter, '\n')
    cat( 'leiden_find_partition: num_iter             ', num_iter, '\n')
    cat( 'leiden_find_partition: initial_membership   ', length(initial_membership ), '\n')
    cat( 'leiden_find_partition: edge_weights         ', length( edge_weights ), '\n')
    cat( 'leiden_find_partition: node_sizes           ', length( node_sizes ), '\n')
    cat( 'leiden_find_partition: number vertices      ', num_vertex, '\n' )
    cat( 'leiden_find_partition: number edges         ', num_edge, '\n' )
  }
  
  result = .Call( '_leiden_find_partition', igraph, partition_type, initial_membership, edge_weights, node_sizes, seed, resolution_parameter, num_iter )

  return( result )
}

.onUnload <- function (libpath)
{
  library.dynam.unload("leidenbase", libpath)
}
