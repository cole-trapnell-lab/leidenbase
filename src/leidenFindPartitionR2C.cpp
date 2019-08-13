/* leidenFindPartitionR2C.cpp */

/*
 *   Leidenalg find partition R-C interface.
 *   Copyright (C) 2019  Cole Trapnell <coletrap@uw.edu>
 *   University of Washington, Genome Sciences Department, Seattle, WA
 *
 *  This file is free software: you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free Software
 *  Foundation, either version 3 of the License, or (at your option) any later
 *  version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *  PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with
 *  this program. If not, see http://www.gnu.org/licenses/.
 */

/*! @file leidenFindPartitionR2C.cpp
 *  @brief R to C wrapper that runs the Leidenalg algorithm find_partition function.
 *  The Leiden algorithm is described in
 *  From Louvain to Leiden: guaranteeing well-connected communities.
 *  V. A. Traag and L. Waltman and N. J. van Eck
 *  Scientific Reports (2019)
 *  DOI: 10.1038/s41598-019-41695-z
 *
 *  @param[in]   igraph                 R igraph graph
 *  @param[in]   partition_type         partition type
 *  @param[in]   initial_membership     Numeric vector of initial membership assignments of nodes (NULL for default of one community per node)
 *  @param[in]   edge_weights           Numeric vector of edge weights (NULL for default of 1.0 for all edges)
 *  @param[in]   node_sizes             Numeric vector of node sizes (NULL for default of 1 for all vertices)
 *  @param[in]   seed                   Numeric random number generator seed (NULL for random seed or numeric value > 0)
 *  @param[in]   resolution_parameter   Numeric resolution parameter (numeric value > 0.0)
 *  @param[in]   num_iter               Numeric number of iterations (numeric value >= 0)
 *  @return A named list consisting of a numeric vector of the node memberships (1-based indices),
 *    a numeric quality value, a numeric vector of edge weights within each community,
 *    a numeric vector of edge weights from each community, a numeric vector of edge weights to
 *    each community, total edge weight, and a numeric vector of individual community
 *    modularities.
 *
 *  @note Find additional information in the Leidenalg distribution source files.
 *
 *  |  description subject  |  description source  |
 *  |  :----                |  :----               |
 *  |  introductory information                     |  leiden/doc/source/intro.rst |
 *  |  partitions and their parameters              |  leiden/src/VertexPartitions.py |
 *  |  initial membership/edge weights/node sizes   |  leiden/src/MutableVertexPartition.cpp |
 *
 *  @note The Leiden algorithm paper has a description of the resolution parameter.
 *
 *  @note This function does not support community detection in multiplex graphs.
 */


#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
#include <R.h>
#include <Rinternals.h>
#include <cigraph/igraph.h>
#include <igraph_rinterface.h>
#include "leidenFindPartition.h"

#define DEBUG   0


extern igraph_error_handler_t igraph_error_handler_printignore;


int xcheckParametersRValues( SEXP initial_membership, SEXP edge_weights, SEXP node_sizes, int *fstatus );
int xcheckParametersCValues( char *ppartitionType, double resolutionParameter, std::int32_t numIter, int *fstatus );
std::vector < size_t >* xsetInitialMembership( SEXP initial_membership, size_t numVertex, int *fstatus );
std::vector < double >* xsetEdgeWeights( SEXP edge_weights, size_t numEdge, int *fstatus );
std::vector < size_t >* xsetNodeSizes( SEXP node_sizes, size_t numVertex, int *fstatus );


/*
 * Disable C++ name mangling so that R can find this function.
 */
extern "C"
{
SEXP _leiden_find_partition( SEXP igraph, SEXP partition_type, SEXP initial_membership, SEXP edge_weights, SEXP node_sizes, SEXP seed, SEXP resolution_parameter, SEXP num_iter )
{
  int status;
  std::int32_t cnumIter;
  size_t cseed;
  size_t i;
  size_t numVertex, numEdge;
  double cresolutionParameter;
  double cweightTotal;
  double cquality;
  char *pcpartitionType;

  std::vector < size_t > *pcinitialMembership;
  std::vector < double > *pcedgeWeights;
  std::vector < size_t > *pcnodeSizes;
  std::vector < size_t >  cmembership;
  std::vector < double >  cweightInCommunity;
  std::vector < double >  cweightFromCommunity;
  std::vector < double >  cweightToCommunity;
  std::vector < double >  ccommunityModularity;

  igraph_t igraphGraph;

  xcheckParametersRValues( initial_membership, edge_weights, node_sizes, &status );

  /*
   * Enable attribute handling as instructed in leiden/src/Optimiser.cpp.
   */
  igraph_i_set_attribute_table( &igraph_cattribute_table );

  /*
   * Print error message and return on igraph error. (Default is to
   * abort on error.)
   */
  igraph_set_error_handler( igraph_error_handler_printignore );

  /*
   * Convert R igraph object to an igraph graph using the igraph internal functions.
   */
  R_SEXP_to_igraph( igraph, &igraphGraph );
  numVertex = (size_t)igraph_vcount( &igraphGraph );
  numEdge   = (size_t)igraph_ecount( &igraphGraph );

  /*
   * Extract partition type string.
   */
  pcpartitionType = (char *)CHAR( STRING_ELT( partition_type, 0 ) );

  /*
   * Convert additional parameters.
   */
  cresolutionParameter = asReal( resolution_parameter );

  cnumIter = asInteger( num_iter );

  if( seed == R_NilValue )
  {
    cseed = (size_t)0;
  }
  else
  {
    cseed = asInteger( seed ) >= 0 ? asInteger( seed ) : 0;
  }

  xcheckParametersCValues( pcpartitionType, cresolutionParameter, cnumIter, &status );
  if( status != 0 )
  {
    return( R_NilValue );
  }

  pcinitialMembership = xsetInitialMembership( initial_membership, numVertex, &status );
  if( status != 0 )
  {
    return ( R_NilValue );
  }

  pcedgeWeights = xsetEdgeWeights( edge_weights, numEdge, &status );
  if( status != 0 )
  {
    if( pcinitialMembership != NULL )
      delete pcinitialMembership;
    return ( R_NilValue );
  }

  pcnodeSizes = xsetNodeSizes( node_sizes, numVertex, &status );
  if( status != 0 )
  {
    if( pcinitialMembership != NULL )
      delete pcinitialMembership;
    if( pcedgeWeights != NULL )
      delete pcedgeWeights;
    return ( R_NilValue );
  }

  /*
   * Partition nodes into communities.
   */
   std::string partitionType( pcpartitionType );
   leidenFindPartition( &igraphGraph, partitionType,
                        pcinitialMembership, pcedgeWeights, pcnodeSizes,
                        (size_t)cseed, cresolutionParameter, cnumIter,
                        &cmembership,
                        &cweightInCommunity,
                        &cweightFromCommunity,
                        &cweightToCommunity,
                        &cweightTotal,
                        &ccommunityModularity,
                        &cquality,
                        &status );
  if( status != 0 )
  {
    if( pcinitialMembership != NULL )
      delete pcinitialMembership;
    if( pcedgeWeights != NULL )
      delete pcedgeWeights;
    if( pcnodeSizes != NULL )
      delete pcnodeSizes;
    error( "_leiden_find_partition: bad status: leiden_find_partition" );
    return ( R_NilValue );
  }

  if( pcinitialMembership != NULL )
    delete pcinitialMembership;
  if( pcedgeWeights != NULL )
    delete pcedgeWeights;
  if( pcnodeSizes != NULL )
    delete pcnodeSizes;

  /*
   * Set up to return community membership vector, community modularities, and community quality and
   * return them in an R list.
   * Notes:
   *   o  C-based leiden has 0-based vectors whereas R has 1-based.
   *      Return membership in a 1-based vector.
   *   o  return named list of (1) membership, (2) within community edge weight,
   *      (3) from community edge weight, (4) to community edge weight,
   *      (5) individual community modularity values, and (6) the quality
   *   o  rmembership: return integer vector if length <= MAX32_INT
   *      else return real.
   */
  SEXP rmembership;

  if( numVertex <= INT32_MAX )
  {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: return membership as integer vector\n";
#endif
    rmembership = PROTECT( allocVector( INTSXP, numVertex ) );
    std::int32_t *pival;
    pival = INTEGER( rmembership );
    for( i = 0; i < numVertex; ++i )
    {
      pival[i] = (std::int32_t)( cmembership[i] + 1 );
    }
  }
  else
  {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: return membership as real vector\n";
#endif
    rmembership = PROTECT( allocVector( REALSXP, numVertex ) );
    double *pdval;
    pdval = REAL( rmembership );
    for( i = 0; i < numVertex; ++i )
    {
      pdval[i] = (double)( cmembership[i] + 1 );
    }
  }

  size_t numCommunity;
  numCommunity = ccommunityModularity.size();
  double *pdval;

  SEXP rweightInCommunity = PROTECT( allocVector( REALSXP, numCommunity ) );
  pdval = REAL( rweightInCommunity );
  for( i = 0; i < numCommunity; ++i )
  {
    pdval[i] = cweightInCommunity[i];
  }

  SEXP rweightFromCommunity = PROTECT( allocVector( REALSXP, numCommunity ) );
  pdval = REAL( rweightFromCommunity );
  for( i = 0; i < numCommunity; ++i )
  {
    pdval[i] = cweightFromCommunity[i];
  }

  SEXP rweightToCommunity = PROTECT( allocVector( REALSXP, numCommunity ) );
  pdval = REAL( rweightToCommunity );
  for( i = 0; i < numCommunity; ++i )
  {
    pdval[i] = cweightToCommunity[i];
  }

  SEXP rcommunityModularity = PROTECT( allocVector( REALSXP, numCommunity ) );
  pdval = REAL( rcommunityModularity );
  for( i = 0; i < numCommunity; ++i )
  {
    pdval[i] = ccommunityModularity[i];
  }

  /*
   * Notes:
   *   o  notice the terminating empty string in lstNames.
   */
  const char *lstNames[] = { "membership", "quality", "edge_weight_within_community", "edge_weight_from_community", "edge_weight_to_community", "total_edge_weight", "community_modularity", "" };
  SEXP rresult = PROTECT( mkNamed( VECSXP, lstNames ) );
  SET_VECTOR_ELT( rresult, 0, rmembership );
  SET_VECTOR_ELT( rresult, 1, ScalarReal( cquality ) );
  SET_VECTOR_ELT( rresult, 2, rweightInCommunity );
  SET_VECTOR_ELT( rresult, 3, rweightFromCommunity );
  SET_VECTOR_ELT( rresult, 4, rweightToCommunity );
  SET_VECTOR_ELT( rresult, 5, ScalarReal( cweightTotal ) );
  SET_VECTOR_ELT( rresult, 6, rcommunityModularity );

  UNPROTECT( 6 );

  return ( rresult );
}
} /* end of extern "C" block */


int xcheckParametersRValues( SEXP initial_membership, SEXP edge_weights, SEXP node_sizes, int *fstatus )
{
  if( initial_membership != R_NilValue && ( !isVectorAtomic( initial_membership ) || xlength( initial_membership ) < 1 ) )
  {
    error( "_leiden_find_partition: initial_membership is not a vector" );
  }

  if( edge_weights != R_NilValue && ( !isVectorAtomic( edge_weights ) || xlength( edge_weights ) < 1 ) )
  {
    error( "_leiden_find_partition: edge_weights is not a vector" );
  }

  if( node_sizes != R_NilValue && ( !isVectorAtomic( node_sizes ) || xlength( node_sizes ) < 1 ) )
  {
    error( "_leiden_find_partition: node_sizes is not a vector" );
  }

  *fstatus = -1;

  return( 0 );
}


static const char *partitionTypeList[] =
{ "CPMVertexPartition",             "ModularityVertexPartition",
  "RBConfigurationVertexPartition", "RBERVertexPartition",
  "SignificanceVertexPartition",    "SurpriseVertexPartition" };


/*
 * Check input parameters.
 */
int xcheckParametersCValues( char *ppartitionType, double resolutionParameter, std::int32_t numIter, int *fstatus )
{
  int i;
  int numPartitionType;
  int flag;

  numPartitionType = sizeof( partitionTypeList ) / sizeof(char*);
  flag = 0;
  for( i = 0; i < numPartitionType; ++i )
  {
    if( strcmp( partitionTypeList[i], ppartitionType ) == 0 )
    {
      flag = 1;
    }
  }
  if( flag == 0 )
  {
    error( "_leiden_find_partition: invalid partition_type" );
    *fstatus = -1;
    return ( 0 );
  }

  if( numIter <= 0 )
  {
    error( "_leiden_find_partition: invalid num_iter: value must be > 0" );
    *fstatus = -1;
    return ( 0 );
  }

  if( resolutionParameter < 0.0 )
  {
    error( "_leiden_find_partition: invalid resolution_parameter: value must be > 0.0" );
    *fstatus = -1;
    return ( 0 );
  }

  *fstatus = 0;

  return ( 0 );
}


std::vector < size_t >* xsetInitialMembership( SEXP initial_membership, size_t numVertex, int *fstatus )
{
  std::vector < size_t > *pinitialMembership;

  if( initial_membership == R_NilValue )
  {
    pinitialMembership = NULL;
  }
  else
  {
    size_t i, n;

    n = (size_t)xlength( initial_membership );
    if( n != numVertex )
    {
      error( "_leiden_find_partition: initial_membership and matrix dimension mismatch" );
      *fstatus = -1;
      return ( NULL );
    }

    if( TYPEOF( initial_membership ) == INTSXP )
    {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: initial_membership is an atomic vector of integers\n";
#endif

      int32_t *pval;
      pval = INTEGER( initial_membership );
      pinitialMembership = new std::vector < size_t >( n );
      for( i = 0; i < n; ++i )
      {
        /*
         * Note: C-based leiden has 0-based vectors whereas R has 1-based
         */
        ( *pinitialMembership )[i] = (size_t)pval[i] - 1;
      }
    }
    else
    if( TYPEOF( initial_membership ) == REALSXP )
    {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: initial_membership is an atomic vector of reals\n";
#endif
      double *pval;
      pval = REAL( initial_membership );
      pinitialMembership = new std::vector < size_t >( n );
      for( i = 0; i < n; ++i )
      {
        /*
         * Note: C-based leiden has 0-based vectors whereas R has 1-based
         */
        ( *pinitialMembership )[i] = (size_t)pval[i] - 1;
      }
    }
    else
    {
      error( "_leiden_find_partition: invalid initial_membership type" );
      *fstatus = -1;
      return( NULL );
    }
  }

  *fstatus = 0;
  return ( pinitialMembership );
}


std::vector < double >* xsetEdgeWeights( SEXP edge_weights, size_t numEdge,int *fstatus )
{

  std::vector < double > *pedgeWeights;

  if( edge_weights == R_NilValue  )
  {
    pedgeWeights = NULL;
  }
  else
  {
    size_t i, n;

    n = (size_t)xlength( edge_weights );
    if( n != numEdge )
    {
      error( "_leiden_find_partition: edge_weights and matrix dimension mismatch" );
      *fstatus = -1;
      return ( NULL );
    }

    if( TYPEOF( edge_weights ) == INTSXP )
    {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: edge_weights is an atomic vector of integers\n";
#endif
      int32_t *pval;
      pval = INTEGER( edge_weights );
      pedgeWeights = new std::vector < double >( n );
      for( i = 0; i < n; ++i )
      {
        ( *pedgeWeights )[i] = (double)pval[i];
      }
    }
    else
    if( TYPEOF( edge_weights ) == REALSXP )
    {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: edge_weights is an atomic vector of reals\n";
#endif
      double *pval;
      pval = REAL( edge_weights );
      pedgeWeights = new std::vector < double >( n );
      for( i = 0; i < n; ++i )
      {
        ( *pedgeWeights )[i] = (double)pval[i];
      }
    }
    else
    {
      error( "_leiden_find_partition: invalid edge_weights type" );
      *fstatus = -1;
      return( NULL );
    }
  }


  *fstatus = 0;

  return ( pedgeWeights );
}


std::vector < size_t >* xsetNodeSizes( SEXP node_sizes, size_t numVertex, int *fstatus )
{
  std::vector < size_t > *pnodeSizes;

  if( node_sizes == R_NilValue )
  {
    pnodeSizes = NULL;
  }
  else
  {
    size_t i, n;

    n = (size_t)xlength( node_sizes );
    if( n != numVertex )
    {
      error( "_leiden_find_partition: node_sizes and matrix dimension mismatch" );
      *fstatus = -1;
      return ( NULL );
    }

    if( TYPEOF( node_sizes ) == INTSXP )
    {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: node_sizes is an atomic vector of integers\n";
#endif
      int32_t *pval;
      pval = INTEGER( node_sizes );
      pnodeSizes = new std::vector < size_t >( n );
      for( i = 0; i < n; ++i )
      {
        ( *pnodeSizes )[i] = (size_t)pval[i];
      }
    }
    else
    if( TYPEOF( node_sizes ) == REALSXP )
    {
#if ( DEBUG )
  std::cout << "Debug: _leiden_find_partition: node_sizes is an atomic vector of reals\n";
#endif
      double *pval;
      pval = REAL( node_sizes );
      pnodeSizes = new std::vector < size_t >( n );
      for( i = 0; i < n; ++i )
      {
        ( *pnodeSizes )[i] = (size_t)pval[i];
      }
    }
    else
    {
      error( "_leiden_find_partition: invalid node_sizes type" );
      *fstatus = -1;
      return( NULL );
    }
  }

  *fstatus = 0;

  return ( pnodeSizes );
}


