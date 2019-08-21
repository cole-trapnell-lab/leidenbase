library(igraph)
library( leidenbase )

#
# Get igraph object
#
fname <- 'igraph_n1500_edgelist.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  igraph <- read_graph( file = zfp, format='edgelist', n=1500 )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

#
# Get target membership vectors
#
fname <- 'cpm_membership_n1500_resp5_nit_2.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  cpm_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

fname <- 'modularity_membership_n1500_resp5_nit_2.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  modularity_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

fname <- 'rbconfiguration_membership_n1500_resp5_nit_2.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  rbconfiguration_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

fname <- 'rbconfiguration_membership_n1500_res1_nit_2.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  rbconfiguration_res1_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

fname <- 'rbconfiguration_membership_n1500_resp5_nit_5.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  rbconfiguration_nit5_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

fname <- 'rber_membership_n1500_resp5_nit_2.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  rber_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

fname <- 'significance_membership_n1500_resp5_nit_2.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  significance_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}

fname <- 'surprise_membership_n1500_resp5_nit_2.txt.gz'
fpath <- system.file( 'testdata', fname, package = 'leidenbase' )
if( length( fpath ) > 0 )
{
  zfp <- gzfile( fpath )
  surprise_membership <- as.integer( read.table( file = zfp ) )
} else {
  stop( 'Error: unable to find file ', fname, '\n' )
}


#
# Test partition types.
#
res <- leiden_find_partition( igraph, partition_type = 'CPMVertexPartition', seed = 123456, resolution_parameter = 0.5 )
test_that( 'CPMVertexPartition membership and quality',
{
  expect_true( all.equal( cpm_membership, res$membership ) )
  expect_true( all.equal( 11575, res$quality, tolerance = 1.0e-6 ) )
})

res <- leiden_find_partition( igraph, partition_type = 'ModularityVertexPartition', seed = 123456, resolution_parameter = 0.5 )
test_that( 'ModularityVertexPartition membership and quality',
{
  expect_true( all.equal( modularity_membership, res$membership ) )
  expect_true( all.equal( 0.7773285, res$quality, tolerance = 1.0e-6 ) )
})

res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', seed = 123456, resolution_parameter = 0.5 )
test_that( 'RBConfigurationVertexPartition membership and quality',
{
  expect_true( all.equal( rbconfiguration_membership, res$membership ) )
  expect_true( all.equal( 52882.31, res$quality, tolerance = 1.0e-6 ) )
})

res <- leiden_find_partition( igraph, partition_type = 'RBERVertexPartition', seed = 123456, resolution_parameter = 0.5 )
test_that( 'RBERVertexPartition membership and quality',
{
  expect_true( all.equal( rber_membership, res$membership ) )
  expect_true( all.equal( 53124.74, res$quality, tolerance = 1.0e-6 ) )
})

res <- leiden_find_partition( igraph, partition_type = 'SignificanceVertexPartition', seed = 123456, resolution_parameter = 0.5 )
test_that( 'SignificanceVertexPartition membership and quality', 
{
  expect_true( all.equal( significance_membership, res$membership ) )
  expect_true( all.equal( 98230.78, res$quality, tolerance = 1.0e-6 ) )
})

res <- leiden_find_partition( igraph, partition_type = 'SurpriseVertexPartition', seed = 123456, resolution_parameter = 0.5 )
test_that( 'SurpriseVertexPartition membership and quality', 
{
  expect_true( all.equal( surprise_membership, res$membership ) )
  expect_true( all.equal( 13864.21, res$quality, tolerance = 1.0e-6 ) )
})


#
# Test resolution_parameter and num_iter.
#
res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', resolution_parameter = 1, seed = 123456 )
test_that( 'resolution_parameter',
{
  expect_true( all.equal( rbconfiguration_res1_membership, res$membership ) )
  expect_true( all.equal( 47911.42, res$quality, tolerance = 1.0e-6 ) )
})

res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', num_iter = 5, seed = 123456, resolution_parameter = 0.5 )
test_that( 'num_iter',
{
  expect_true( all.equal( rbconfiguration_nit5_membership, res$membership ) )
  expect_true( all.equal( 52904.31, res$quality, tolerance = 1.0e-6 ) )
})


#
# Test initial_membership
#
inimem <- as.integer( seq( 1, 1500 ) )
res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', initial_membership = inimem, seed = 123456, resolution_parameter = 0.5 )
test_that( 'RBConfigurationVertexPartition membership and quality',
{
  expect_true( all.equal( rbconfiguration_membership, res$membership ) )
  expect_true( all.equal( 52882.31, res$quality, tolerance = 1.0e-6 ) )
})


#
# Test edge_weights
#
edgwgt <- as.double( rep( 1.0, 61636 ) )
res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', edge_weights = edgwgt, seed = 123456, resolution_parameter = 0.5 )
test_that( 'RBConfigurationVertexPartition membership and quality',
{
  expect_true( all.equal( rbconfiguration_membership, res$membership ) )
  expect_true( all.equal( 52882.31, res$quality, tolerance = 1.0e-6 ) )
})


#
# Test node_sizes
#
nodsiz <- as.integer( rep( 1, 1500 ) )
res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', node_sizes = nodsiz, seed = 123456, resolution_parameter = 0.5 )
test_that( 'RBConfigurationVertexPartition membership and quality',
{
  expect_true( all.equal( rbconfiguration_membership, res$membership ) )
  expect_true( all.equal( 52882.31, res$quality, tolerance = 1.0e-6 ) )
})


#
# Test parameter errors
#
egraph <- ''
test_that( 'igraph',
{
  expect_error( leiden_find_partition( egraph ) )
})

inimem <- inimem <- as.integer( seq( 1, 1400 ) )
test_that( 'initial_membership',
{
  expect_error( leiden_find_partition( igraph, initial_membership = inimem, resolution_parameter = 0.5 ) )
})

edgwgt <- as.double( rep( 1.0, 61630 ) )
test_that( 'edge_weights',
{
  expect_error( leiden_find_partition( igraph, edge_weights = edgwgt, resolution_parameter = 0.5 ) )
})

nodsiz <- inimem <- as.integer( seq( 1, 1400 ) )
test_that( 'node_sizes',
{
  expect_error( leiden_find_partition( igraph, node_sizes = nodsiz, resolution_parameter = 0.5 ) )
})

test_that( 'resolution_parameter',
{
  expect_error( leiden_find_partition( igraph, resolution_parameter = 0.0 ) )
})

test_that( 'num_iter',
{
  expect_error( leiden_find_partition( igraph, num_iter = 0, resolution_parameter = 0.5 ) )
})

