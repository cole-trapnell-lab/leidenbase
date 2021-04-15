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
  int version_major;
  int version_minor;
  int version_subminor;

  size_t i, j, ncomm;
  char string[1024];
  char fn[8192];

  const char *igraphVersion;

  double resolution_parameter;
  double weightTotal;
  double quality;
  double modularity;
  double significance;
  igraph_t i_graph;

  igraph_integer_t numVertex;
  igraph_integer_t numEdge;

  FILE *fp;


  igraph_version( NULL, &version_major, &version_minor, &version_subminor );

  fprintf( stdout, "igraph version %d.%d.%d\n", version_major, version_minor, version_subminor );

  strcpy( fn, "edgelist.edg" );

  fp = fopen( fn, "r" );
  if( fp == NULL )
  {
    fprintf( stderr, "Error: unable to open file %s\n" );
    return( -1 );
  }

  status = igraph_read_graph_edgelist( &i_graph, fp, 0, false );

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
  resolution_parameter = 0.5;
  n_iter               = 2;
  std::vector<size_t>  membership;
  std::vector<double>  weightInCommunity;
  std::vector<double>  weightFromCommunity;
  std::vector<double>  weightToCommunity;
  leidenFindPartition( &i_graph,
                         "CPMVertexPartition",
                         NULL,
                         NULL,
                         NULL,
                         2016,
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
  ncomm = 0;
  for( i = 0; i < numVertex - 1; ++i )
  {
//    fprintf( stdout, "%d %d\n", i, membership[i] );
    if( membership[i] > ncomm ) ncomm = membership[i];
  }
//  fprintf( stdout, "%d %d\n", numVertex-1,  membership[numVertex-1] + 1 );
  if( membership[numVertex-1] > ncomm ) ncomm = membership[numVertex-1];

  for( j = 0; j <= ncomm; ++j )
  {
    fprintf( stdout, "%3d:", j );
    for( i = 0; i < numVertex - 1; ++i )
    {
      if( membership[i] == j )
        fprintf( stdout, " %d", i );
    }
    fprintf( stdout, "\n" );
  }
  
#endif

  igraph_destroy( &i_graph );

  return( 0 );
}

