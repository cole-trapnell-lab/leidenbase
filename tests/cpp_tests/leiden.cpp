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

  size_t i, j, mxcomm;
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

  fprintf( stderr, "igraph version %d.%d.%d\n", version_major, version_minor, version_subminor );

  strcpy( fn, "edgelist.edg" );

  fp = fopen( fn, "r" );
  if( fp == NULL )
  {
    fprintf( stderr, "Error: unable to open file %s\n", fn );
    return( -1 );
  }

  /*
  ** From igraph documentation:
  **   int igraph_read_graph_edgelist(igraph_t *graph, FILE *instream, 
  **                                  igraph_integer_t n,
  **                                  igraph_bool_t directed);
  **
  **   Arguments: 
  **     graph:     Pointer to an uninitialized graph object.
  **     instream:  Pointer to a stream, it should be readable.
  **     n:         The number of vertices in the graph. If smaller
  **                than the largest integer in the file it will be
  **                ignored. It is thus safe to supply zero here.
  **     directed:  Logical, if true the graph is directed, if
  **                false it will be undirected. 
  */
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
  mxcomm = 0;
  for( i = 0; i < numVertex; ++i )
  {
    if( membership[i] > mxcomm ) mxcomm = membership[i];
  }

  for( j = 0; j <= mxcomm; ++j )
  {
    fprintf( stdout, "[%d]", j );
    for( i = 0; i < numVertex; ++i )
    {
      if( membership[i] == j )
        fprintf( stdout, " %d", i );
    }
    fprintf( stdout, "\n\n" );
  }

  /*
  ** The weightTotal value returned by leidenFindPartition
  ** appears to be the number of graph edges (or the number
  ** of edges * 2 for undirected graphs).
  **
  ** The total weight in all communities is the sum of
  ** the weights in each community. This value is not
  ** give here.
  */

  fprintf( stdout, "\n" );
  fprintf( stdout, "Quality: %f\n", quality );  
  fprintf( stdout, "Total weight: %f\n", weightTotal );  
  fprintf( stdout, "Modularity: %f\n", modularity );  
  fprintf( stdout, "Significance: %f\n", significance );

  fprintf( stdout, "\n\n" );
  fprintf( stdout, "Edge weight within community\n" );
  for( j = 0; j <= mxcomm; ++j )
  {
    fprintf( stdout, " %.0f", weightInCommunity[j] );
  }

  fprintf( stdout, "\n\n" );
  fprintf( stdout, "Edge weight from community\n" );
  for( j = 0; j <= mxcomm; ++j )
  {
    fprintf( stdout, " %.0f", weightFromCommunity[j] );
  }

  fprintf( stdout, "\n\n" );
  fprintf( stdout, "Edge weight to community\n" );
  for( j = 0; j <= mxcomm; ++j )
  {
    fprintf( stdout, " %.0f", weightToCommunity[j] );
  }

  fprintf( stdout, "\n\n" );
#endif

  igraph_destroy( &i_graph );

  return( 0 );
}

