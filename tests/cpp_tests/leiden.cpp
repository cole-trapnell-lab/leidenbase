/** leiden.cpp **/

#define FULL_TEST


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
#include </usr/local/include/igraph/igraph.h>

int leidenFindPartition( igraph_t *pigraph,
                           std::string const partitionType,
                           std::vector < size_t > const *pinitialMembership,
                           std::vector < double > const *pedgeWeights,
                           std::vector < size_t > const *pnodeSizes,
                           size_t seed,
                           double resolutionParameter,
                           int32_t numIter,
                           std::vector < size_t > *pmembership,
                           std::vector < double > *pweightInCommunity,
                           std::vector < double > *pweightFromCommunity,
                           std::vector < double > *pweightToCommunity,
                           double *pweightTotal,
                           double *pquality,
                           double *pmodularity,
                           double *psignificance,
                           int *pstatus );

int main( int argc, char **argv )
{
  int n_iter;
  int status;

  size_t i, ncomm;
  char string[1024];
  char fn[8192];

  double resolution_parameter;
  double weightTotal;
  double quality;
  double modularity;
  double significance;
  igraph_t i_graph;

  igraph_integer_t numVertex;
  igraph_integer_t numEdge;

  FILE *fp;

  strcpy( fn, "igraph_edgelist.txt" );

  fp = fopen( fn, "r" );
  if( fp == NULL )
  {
    fprintf( stderr, "Error: unable to open file %s\n" );
    return( -1 );
  }

  status = igraph_read_graph_edgelist( &i_graph, fp, 0, IGRAPH_ADJ_DIRECTED );
  if( status != 0 )
  {
    fprintf( stderr, "Error: bad status: igraph_read_graph_edgelist\n" );
    return( -1 );
  }

  numVertex = igraph_vcount( &i_graph );
  numEdge   = igraph_ecount( &i_graph );

#ifdef FULL_TEST
  std::vector<size_t> initial_membership;
  initial_membership.resize( numVertex );
  for( i = 0; i < numVertex; ++i )
  {
    initial_membership[i] = 1;
  }

  std::vector<double> weights;
  weights.resize( numEdge );
  for( i = 0; i < numEdge; ++i )
  {
    weights[i] = 1.0;
  }

  std::vector<size_t> node_sizes;
  node_sizes.resize( numVertex );
  for( i = 0; i < numVertex; ++i )
  {
    node_sizes[i] = 1;
  }
#endif

  /*
  ** Partition types:
  **   CPMVertexPartition
  **   ModularityVertexPartition
  **   RBConfigurationVertexPartition
  **   RBERVertexPartition
  **   SignificanceVertexPartition
  **   SurpriseVertexPartition
  */   
  resolution_parameter = 0.1;
  n_iter               = 2;
  std::vector<size_t>  membership;
  std::vector<double>  weightInCommunity;
  std::vector<double>  weightFromCommunity;
  std::vector<double>  weightToCommunity;
  leidenFindPartition( &i_graph,
                         "RBConfigurationVertexPartition",
                         NULL,
                         NULL,
                         NULL,
                         123456,
                         resolution_parameter,
                         n_iter,
                         &membership,
                         &weightInCommunity,
                         &weightFromCommunity,
                         &weightToCommunity,
                         &weightTotal,
                         &quality,
                         &modularity,
                         &significance,
                         &status );
  if( status != 0 )
  {
    fprintf( stderr, "Error: bad status: leiden_find_partition\n" );
    return( -1 );
  }

#ifdef FULL_TEST
  for( i = 0; i < numVertex - 1; ++i )
  {
    fprintf( stdout, "%d ", membership[i] + 1 );
  }
  fprintf( stdout, "%d\n", membership[numVertex-1] + 1 );
#endif

  igraph_destroy( &i_graph );

  return( 0 );
}

