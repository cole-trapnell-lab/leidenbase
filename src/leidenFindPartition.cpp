/* leidenFindPartition.cpp */

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

/*! @file leidenFindPartition.cpp
 *  @brief C++ wrapper that runs the Leiden community detection algorithm
 *     find_partition function, which is given in the Leidenalg
 *     distribution file 'leiden/src/functions.py'.
 *  The Leiden algorithm is described in
 *  From Louvain to Leiden: guaranteeing well-connected communities.
 *  V. A. Traag, L. Waltman, and N. J. van Eck
 *  Scientific Reports (2019)
 *  DOI: 10.1038/s41598-019-41695-z
 *
 *  @param[in]   igraph                pointer to igraph_t graph
 *  @param[in]   partitionType         partition type used for optimization
 *  @param[in]   initialMembership     initial membership assignments of nodes (NULL for default of one community per node)
 *  @param[in]   edgeWeights           weights of edges (NULL for default of 1.0)
 *  @param[in]   nodeSizes             node sizes (NULL for default of 1)
 *  @param[in]   seed                  random number generator seed (0=random seed)
 *  @param[in]   resolutionParameter   resolution parameter
 *  @param[in]   numIter               number of iterations
 *  @param[out]  pmembership           node membership assignments
 *  @param[out]  pquality              partition quality
 *  @param[out]  psignificance         partition significance
 *  @param[out]  pstatus               function status (0=success; -1=failure)
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
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <igraph.h>

#include "GraphHelper.h"
#include "CPMVertexPartition.h"
#include "ModularityVertexPartition.h"
#include "RBConfigurationVertexPartition.h"
#include "RBERVertexPartition.h"
#include "SignificanceVertexPartition.h"
#include "SurpriseVertexPartition.h"
#include "Optimiser.h"
#include "leidenFindPartition.h"

#define DEBUG   0


int xdumpParameters( igraph_t *pigraph,
                      std::string const partitionType,
                      std::vector < size_t > const *pinitialMembership,
                      std::vector < double > const *pedgeWeights,
                      std::vector < size_t > const *pnodeSizes,
                      size_t seed,
                      double resolutionParameter,
                      std::int32_t numIter,
                      int *pstatus );
int
xcheckParameters( std::string const partitionType,
                   std::vector < size_t > const *pinitialMembership,
                   std::vector < double > const *pedgeWeights,
                   std::vector < size_t > const *pnodeSizes,
                   size_t numVertex, size_t numEdge,
                   double resolutionParameter, std::int32_t numIter, int *pstatus );
Graph*
xmakeGraph( igraph_t *pigraph, std::vector < double > const *pedgeWeights,
             std::vector < size_t > const *pnodeSizes, int correctSelfLoops,
             int *pstatus );

MutableVertexPartition*
xmakePartition( Graph *pGraph, std::string const partitionType,
                 std::vector < size_t > const *pinitialMembership,
                 double resolutionParameter, int *pstatus );
int xgetQuality( MutableVertexPartition *ppartition, std::string const partitionType, double resolutionParameter, double *pquality, int *pstatus );

int xgetCommunityValues( MutableVertexPartition *ppartition, Graph *pGraph, std::vector < double > *pweightInCommunity, std::vector < double > *pweightFromCommunity, std::vector < double > *pweightToCommunity, double *pweightTotal, int *pstatus );


int leidenFindPartition( igraph_t *pigraph,
                           std::string const partitionType,
                           std::vector < size_t > const *pinitialMembership,
                           std::vector < double > const *pedgeWeights,
                           std::vector < size_t > const *pnodeSizes,
                           size_t seed,
                           double resolutionParameter,
                           std::int32_t numIter,
                           std::vector < size_t > *pmembership,
                           std::vector < double > *pweightInCommunity,
                           std::vector < double > *pweightFromCommunity,
                           std::vector < double > *pweightToCommunity,
                           double *pweightTotal,
                           double *pquality,
                           double *psignificance,
                           int *pstatus )
{
  int correctSelfLoops;
  int status;
  std::int32_t iiter;

  size_t numVertex;
  size_t numEdge;

  Graph *pGraph;
  MutableVertexPartition *ppartition;

#if ( DEBUG )
  xdumpParameters( pigraph, partitionType, pinitialMembership, pedgeWeights, pnodeSizes, seed, resolutionParameter, numIter, &status );
  if( status != 0 )
  {
    *pstatus = -1;
    return ( 0 );
  }
#endif

  numVertex = igraph_vcount( pigraph );
  numEdge = igraph_ecount( pigraph );

  /*
   * Check input parameters.
   */
  xcheckParameters( partitionType, pinitialMembership, pedgeWeights,
                     pnodeSizes, numVertex, numEdge,
                     resolutionParameter, numIter, &status );
  if( status != 0 )
  {
    *pstatus = -1;
    return ( 0 );
  }

  /*
   ** Make Graph (defined in GraphHelper.h)
   */
  correctSelfLoops = 0;
  pGraph = xmakeGraph( pigraph, pedgeWeights, pnodeSizes, correctSelfLoops,
                        &status );
  if( status != 0 )
  {
    *pstatus = -1;
    return ( 0 );
  }

  /*
   ** Make specified partition.
   */
  ppartition = xmakePartition( pGraph, partitionType, pinitialMembership,
                                resolutionParameter, &status );
  if( status != 0 )
  {
    delete pGraph;
    *pstatus = -1;
    return ( 0 );
  }

  /*
   * Make optimiser object.
   */
  Optimiser optimiser;

  /*
   * Set random number generator seed if seed > 0.
   */
  if( seed > 0 )
  {
    optimiser.set_rng_seed( seed );
  }

  /*
   * Run optimiser.
   */
  for( iiter = 0; iiter < numIter; ++iiter )
  {
    optimiser.optimise_partition( ppartition );
  }

  /*
   * Prepare to return membership assignments.
   */
  ( *pmembership ).resize( numVertex );
  size_t i;
  for( i = 0; i < numVertex; ++i )
  {
    ( *pmembership )[i] = ppartition->membership( i );
  }

  /*
   * Get final quality.
   * Notes:
   *   o  the Leiden code notes that this quality is not normalized by
   *      the number of edges.
   */
  xgetQuality( ppartition, partitionType, resolutionParameter, pquality, &status );
  if( status != 0 )
  {
    delete pGraph;
    delete ppartition;
    *pstatus = -1;
    return ( 0 );
  }

#if ( DEBUG )
  std::cout << "Debug: leidenFindPartition: quality: " << *pquality << "\n";
#endif

#if ( DEBUG )
  std::cout << "Debug: leidenFindPartition: done\n";
#endif

  /*
   * Get community values.
   */
  xgetCommunityValues( ppartition, pGraph, pweightInCommunity, pweightFromCommunity, pweightToCommunity, pweightTotal, &status );
  if( status != 0 )
  {
    delete pGraph;
    delete ppartition;
    *pstatus = -1;
    return ( 0 );
  }

  delete pGraph;
  delete ppartition;
  *pstatus = 0;

  return ( 0 );
}


static const char *partitionTypeList[] =
{
  "CPMVertexPartition",
  "ModularityVertexPartition",
  "RBConfigurationVertexPartition",
  "RBERVertexPartition",
  "SignificanceVertexPartition",
  "SurpriseVertexPartition"
};


int xdumpParameters( igraph_t *pigraph,
                      std::string const partitionType,
                      std::vector < size_t > const *pinitialMembership,
                      std::vector < double > const *pedgeWeights,
                      std::vector < size_t > const *pnodeSizes,
                      size_t seed,
                      double resolutionParameter,
                      std::int32_t numIter,
                      int *pstatus )
{
  std::cout << "Debug: leidenFindPartition: start\n";
  std::cout
      << "Debug: leidenFindPartition: partitionType: " + partitionType
         + "\n";
  if( pinitialMembership == NULL )
  {
    std::cout << "Debug: leidenFindPartition: initialMembership is NULL\n";
  }
  else
  {
    std::cout
        << "Debug: leidenFindPartition: initialMembership is not NULL\n";
  }
  if( pedgeWeights == NULL )
  {
    std::cout << "Debug: leidenFindPartition: edgeWeights is NULL\n";
  }
  else
  {
    std::cout << "Debug: leidenFindPartition: edgeWeights is not NULL\n";
  }
  if( pnodeSizes == NULL )
  {
    std::cout << "Debug: leidenFindPartition: nodeSizes is NULL\n";
  }
  else
  {
    std::cout << "Debug: leidenFindPartition: nodeSizes is not NULL\n";
  }
  std::cout << "Debug: leidenFindPartition: resolutionParameter is " << resolutionParameter << "\n";
  std::cout << "Debug: leidenFindPartition: seed:      " << seed << "\n";
  std::cout << "Debug: leidenFindPartition: numIter:   " << numIter << "\n";
  std::cout << "Debug: leidenFindPartition: numVertex: " << igraph_vcount( pigraph ) << "\n";
  std::cout << "Debug: leidenFindPartition: numEdges:  " << igraph_ecount( pigraph ) << "\n";

  *pstatus = 0;

  return( 0 );
}


/*
 * Check input parameter reasonableness.
 */
int xcheckParameters( std::string const partitionType,
                       std::vector < size_t > const *pinitialMembership,
                       std::vector < double > const *pedgeWeights,
                       std::vector < size_t > const *pnodeSizes,
                       size_t numVertex, size_t numEdge,
                       double resolutionParameter, std::int32_t numIter, int *pstatus )
{
  int numPartitionType;
  int i;
  int flag;

  numPartitionType = sizeof( partitionTypeList ) / sizeof(char*);
  flag = 0;
  for( i = 0; i < numPartitionType; ++i )
  {
    if( partitionType.compare( partitionTypeList[i] ) == 0 )
    {
      flag = 1;
    }
  }
  if( flag == 0 )
  {
    std::cout << "Error: leidenbase: invalid partitionType\n";
    *pstatus = -1;
    return ( 0 );
  }

  if( pinitialMembership != NULL && pinitialMembership->size() != numVertex )
  {
    std::cout << "leidenFindPartition: Initial membership vector inconsistent length with the vertex count of the graph.\n";
    *pstatus = -1;
    return ( 0 );
  }

  if( pedgeWeights != NULL && pedgeWeights->size() != numEdge )
  {
    std::cout << "leidenFindPartition: Edge weight vector inconsistent length with the edge count of the graph.\n";
    *pstatus = -1;
    return ( 0 );
  }

  if( pnodeSizes != NULL && pnodeSizes->size() != numVertex )
  {
    std::cout << "leidenFindPartition: Node size vector inconsistent length with the vertex count of the graph.\n";
    *pstatus = -1;
    return ( 0 );
  }

  if( resolutionParameter <= 0.0 )
  {
    std::cout << "leidenFindPartition: resolution parameter <= 0.0\n";
    *pstatus = -1;
    return ( 0 );
  }

  if( numIter <= 0 )
  {
    std::cout << "leidenFindPartition: Number of iterations <= 0.\n";
    *pstatus = -1;
    return ( 0 );
  }

  *pstatus = 0;

  return ( 0 );
}


/*
 * Make Leiden Graph object from igraph graph object.
 */
Graph*
xmakeGraph( igraph_t *pigraph, std::vector < double > const *pedgeWeights,
             std::vector < size_t > const *pnodeSizes, int correctSelfLoops,
             int *pstatus )
{
  Graph *pGraph;

  if( pedgeWeights != NULL && pnodeSizes != NULL )
  {
    pGraph = new Graph( pigraph, *pedgeWeights, *pnodeSizes,
                        correctSelfLoops );
  }
  else if( pedgeWeights != NULL && pnodeSizes == NULL )
  {
    pGraph = new Graph( pigraph, *pedgeWeights, correctSelfLoops );
  }
  else if( pedgeWeights == NULL && pnodeSizes != NULL )
  {
    pGraph = new Graph( pigraph, *pnodeSizes, correctSelfLoops );
  }
  else
  {
    pGraph = new Graph( pigraph, correctSelfLoops );
  }

  *pstatus = 0;

  return ( pGraph );
}


/*
 * Make requested partition object.
 */
MutableVertexPartition*
xmakePartition( Graph *pGraph, std::string const partitionType,
                 std::vector < size_t > const *pinitialMembership,
                 double resolutionParameter, int *pstatus )
{
  MutableVertexPartition *ppartition;

  if( partitionType.compare( "CPMVertexPartition" ) == 0 )
  {
    if( pinitialMembership != NULL )
    {
      ppartition = new CPMVertexPartition( pGraph, *pinitialMembership, resolutionParameter );
    }
    else
    {
      ppartition = new CPMVertexPartition( pGraph, resolutionParameter );
    }
  }
  else if( partitionType.compare( "ModularityVertexPartition" ) == 0 )
  {
    if( pinitialMembership != NULL )
    {
      ppartition = new ModularityVertexPartition( pGraph, *pinitialMembership );
    }
    else
    {
      ppartition = new ModularityVertexPartition( pGraph );
    }
  }
  else if( partitionType.compare( "RBConfigurationVertexPartition" ) == 0 )
  {
    if( pinitialMembership != NULL )
    {
      ppartition = new RBConfigurationVertexPartition( pGraph,
                                                       *pinitialMembership,
                                                       resolutionParameter );
    }
    else
    {
      ppartition = new RBConfigurationVertexPartition( pGraph, resolutionParameter );
    }
  }
  else if( partitionType.compare( "RBERVertexPartition" ) == 0 )
  {
    if( pinitialMembership != NULL )
    {
      ppartition = new RBERVertexPartition( pGraph, *pinitialMembership, resolutionParameter );
    }
    else
    {
      ppartition = new RBERVertexPartition( pGraph, resolutionParameter );
    }
  }
  else if( partitionType.compare( "SignificanceVertexPartition" ) == 0 )
  {
    if( pinitialMembership != NULL )
    {
      ppartition = new SignificanceVertexPartition( pGraph, *pinitialMembership );
    }
    else
    {
      ppartition = new SignificanceVertexPartition( pGraph );
    }
  }
  else if( partitionType.compare( "SurpriseVertexPartition" ) == 0 )
  {
    if( pinitialMembership != NULL )
    {
      ppartition = new SurpriseVertexPartition( pGraph, *pinitialMembership );
    }
    else
    {
      ppartition = new SurpriseVertexPartition( pGraph );
    }
  }
  else
  {
    std::cout << "leidenFindPartition: Unrecognized vertex partition type\n";
    *pstatus = -1;
    return ( NULL );
  }

  *pstatus = 0;

  return ( ppartition );
}


/*
 * Get quality of partition.
 */
int xgetQuality( MutableVertexPartition *ppartition, std::string const partitionType, double resolutionParameter, double *pquality, int *pstatus )
{
  *pquality = 0.0;
  if( partitionType.compare( "CPMVertexPartition" ) == 0 )
  {
    *pquality = dynamic_cast< CPMVertexPartition * > (ppartition)->quality( resolutionParameter );
  }
  else if( partitionType.compare( "ModularityVertexPartition" ) == 0 )
  {
    *pquality = dynamic_cast< ModularityVertexPartition * > (ppartition)->quality();
  }
  else if( partitionType.compare( "RBConfigurationVertexPartition" ) == 0 )
  {
    *pquality = dynamic_cast< RBConfigurationVertexPartition * > (ppartition)->quality( resolutionParameter );
  }
  else if( partitionType.compare( "RBERVertexPartition" ) == 0 )
  {
    *pquality = dynamic_cast< RBERVertexPartition * > (ppartition)->quality( resolutionParameter );
  }
  else if( partitionType.compare( "SignificanceVertexPartition" ) == 0 )
  {
    *pquality = dynamic_cast< SignificanceVertexPartition * > (ppartition)->quality();
  }
  else if( partitionType.compare( "SurpriseVertexPartition" ) == 0 )
  {
    *pquality = dynamic_cast< SurpriseVertexPartition * > (ppartition)->quality();
  }
  else
  {
    std::cout << "leidenFindPartition: Unrecognized vertex partition type\n";
    *pstatus = -1;
    return ( 0 );
  }

  *pstatus = 0;

  return ( 0 );
}


/*
 * Get some community values.
 */
int xgetCommunityValues( MutableVertexPartition *ppartition, Graph *pGraph, std::vector < double > *pweightInCommunity, std::vector < double > *pweightFromCommunity, std::vector < double > *pweightToCommunity, double *pweightTotal, int *pstatus )
{
  double mod;
  double m;
  double w;
  double w_in;
  double w_out;

  size_t icomm, numCommunity;

  numCommunity = ppartition->n_communities();

  if( pGraph->is_directed() )
  {
    m = pGraph->total_weight();
  }
  else
  {
    m = 2 * pGraph->total_weight();
  }

  *pweightTotal = m;

  if( m == 0 )
  {
    *pstatus = -1;
    return( 0 );
  }

  pweightInCommunity->resize( numCommunity );
  pweightFromCommunity->resize( numCommunity );
  pweightToCommunity->resize( numCommunity );

  for( icomm = 0; icomm < numCommunity; ++icomm )
  {
    w     = ppartition->total_weight_in_comm( icomm );
    w_out = ppartition->total_weight_from_comm( icomm );
    w_in  = ppartition->total_weight_to_comm( icomm );
    ( *pweightInCommunity )[icomm]   = w;
    ( *pweightFromCommunity )[icomm] = w_out;
    ( *pweightToCommunity )[icomm]   = w_in;
  }

  *pstatus = 0;

  return( 0 );
}

