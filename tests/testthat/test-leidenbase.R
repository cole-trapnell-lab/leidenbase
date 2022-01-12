library(igraph)
library( leidenbase )

run_setup <- FALSE
dst_dir <- paste0(system.file(package='leidenbase'), '/testdata')
evf <- paste0(dst_dir, '/expected_values.txt')

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

if(run_setup) {
  system(paste0('rm ',  evf))
} else {
  source(evf)
}

#
# Test partition types.
#
test_that( 'CPMVertexPartition membership and quality',
{
  res <- leiden_find_partition( igraph, partition_type = 'CPMVertexPartition', seed = 123456, resolution_parameter = 0.5 )
  t01_f01 <- 'test01_file01.txt'
  t01_v01 <- res$membership
  t01_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t01_f01)
  if(run_setup) {
    write.table(t01_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t01_v02_expect <- %.2f\n", t01_v02), file=evf, append=TRUE)
  }
  else {
    t01_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t01_v01_expect, t01_v01)))
    expect_true(isTRUE(all.equal(t01_v02_expect, t01_v02, tolerance = 1.0e-2)))
  }
})

test_that( 'ModularityVertexPartition membership and quality',
{
  res <- leiden_find_partition( igraph, partition_type = 'ModularityVertexPartition', seed = 123456, resolution_parameter = 0.5 )
  t02_f01 <- 'test02_file01.txt'
  t02_v01 <- res$membership
  t02_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t02_f01)
  if(run_setup) {
    write.table(t02_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t02_v02_expect <- %.4f\n", t02_v02), file=evf, append=TRUE)
  }
  else {
    t02_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t02_v01_expect, t02_v01)))
    expect_true(isTRUE(all.equal(t02_v02_expect, t02_v02, tolerance = 1.0e-4)))
  }
})

test_that( 'RBERVertexPartition membership and quality',
{
  res <- leiden_find_partition( igraph, partition_type = 'RBERVertexPartition', seed = 123456, resolution_parameter = 0.5 )
  t03_f01 <- 'test03_file01.txt'
  t03_v01 <- res$membership
  t03_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t03_f01)
  if(run_setup) {
    write.table(t03_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t03_v02_expect <- %.2f\n", t03_v02), file=evf, append=TRUE)
  }
  else {
    t03_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t03_v01_expect, t03_v01)))
    expect_true(isTRUE(all.equal(t03_v02_expect, t03_v02, tolerance = 1.0e-2)))
  }
})

test_that( 'SignificanceVertexPartition membership and quality', 
{
  res <- leiden_find_partition( igraph, partition_type = 'SignificanceVertexPartition', seed = 123456, resolution_parameter = 0.5 )
  t04_f01 <- 'test04_file01.txt'
  t04_v01 <- res$membership
  t04_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t04_f01)
  if(run_setup) {
    write.table(t04_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t04_v02_expect <- %.2f\n", t04_v02), file=evf, append=TRUE)
  }
  else {
    t04_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t04_v01_expect, t04_v01)))
    expect_true(isTRUE(all.equal(t04_v02_expect, t04_v02, tolerance = 1.0e-2)))
  }
})

test_that( 'SurpriseVertexPartition membership and quality', 
{
  res <- leiden_find_partition( igraph, partition_type = 'SurpriseVertexPartition', seed = 123456, resolution_parameter = 0.5 )
  t05_f01 <- 'test05_file01.txt'
  t05_v01 <- res$membership
  t05_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t05_f01)
  if(run_setup) {
    write.table(t05_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t05_v02_expect <- %.2f\n", t05_v02), file=evf, append=TRUE)
  }
  else {
    t05_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t05_v01_expect, t05_v01)))
    expect_true(isTRUE(all.equal(t05_v02_expect, t05_v02, tolerance = 1.0e-2)))
  }
})


#
# Test resolution_parameter and num_iter.
#
test_that( 'resolution_parameter parameter',
{
  res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', resolution_parameter = 1, seed = 123456 )
  t06_f01 <- 'test06_file01.txt'
  t06_v01 <- res$membership
  t06_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t06_f01)
  if(run_setup) {
    write.table(t06_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t06_v02_expect <- %.2f\n", t06_v02), file=evf, append=TRUE)
  }
  else {
    t06_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t06_v01_expect, t06_v01)))
    expect_true(isTRUE(all.equal(t06_v02_expect, t06_v02, tolerance = 1.0e-2)))
  }
})

test_that( 'num_iter parameter',
{
  res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', num_iter = 5, seed = 123456, resolution_parameter = 0.5 )
  t07_f01 <- 'test07_file01.txt'
  t07_v01 <- res$membership
  t07_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t07_f01)
  if(run_setup) {
    write.table(t07_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t07_v02_expect <- %.2f\n", t07_v02), file=evf, append=TRUE)
  }
  else {
    t07_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t07_v01_expect, t07_v01)))
    expect_true(isTRUE(all.equal(t07_v02_expect, t07_v02, tolerance = 1.0e-2)))
  }
})


#
# Test initial_membership
#
test_that( 'initial_membership parameter',
{
  inimem <- as.integer( seq( 1, 1500 ) )
  res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', initial_membership = inimem, seed = 123456, resolution_parameter = 0.5 )
  t08_f01 <- 'test08_file01.txt'
  t08_v01 <- res$membership
  t08_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t08_f01)
  if(run_setup) {
    write.table(t08_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t08_v02_expect <- %.2f\n", t08_v02), file=evf, append=TRUE)
  }
  else {
    t08_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t08_v01_expect, t08_v01)))
    expect_true(isTRUE(all.equal(t08_v02_expect, t08_v02, tolerance = 1.0e-2)))
  }
})


#
# Test edge_weights
#
test_that( 'edge_weights parameter',
{
  edgwgt <- as.double( rep( 1.0, 61636 ) )
  res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', edge_weights = edgwgt, seed = 123456, resolution_parameter = 0.5 )
  t09_f01 <- 'test09_file01.txt'
  t09_v01 <- res$membership
  t09_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t09_f01)
  if(run_setup) {
    write.table(t09_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t09_v02_expect <- %.2f\n", t09_v02), file=evf, append=TRUE)
  }
  else {
    t09_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t09_v01_expect, t09_v01)))
    expect_true(isTRUE(all.equal(t09_v02_expect, t09_v02, tolerance = 1.0e-2)))
  }
})


#
# Test node_sizes
#
test_that( 'node_sizes parameter',
{
  nodsiz <- as.integer( rep( 1, 1500 ) )
  res <- leiden_find_partition( igraph, partition_type = 'RBConfigurationVertexPartition', node_sizes = nodsiz, seed = 123456, resolution_parameter = 0.5 )
  t10_f01 <- 'test10_file01.txt'
  t10_v01 <- res$membership
  t10_v02 <- res$quality
  fpath <- paste0(dst_dir, '/', t10_f01)
  if(run_setup) {
    write.table(t10_v01, file=fpath, row.names=FALSE, col.names=FALSE)
    cat(sprintf("t10_v02_expect <- %.2f\n", t10_v02), file=evf, append=TRUE)
  }
  else {
    t10_v01_expect <- read.table(fpath)[['V1']]
    expect_true(isTRUE(all.equal(t10_v01_expect, t10_v01)))
    expect_true(isTRUE(all.equal(t10_v02_expect, t10_v02, tolerance = 1.0e-2)))
  }
})

#
# Test modularity and significance return values.
#
test_that( 'modularity and significance return values',
{
  res <- leiden_find_partition( igraph, partition_type = 'CPMVertexPartition', seed = 123456, resolution_parameter = 0.1 )
  t11_v01 <- res$modularity
  t11_v02 <- res$significance
  if(run_setup) {
    cat(sprintf("t11_v01_expect <- %.4f\n", t11_v01), file=evf, append=TRUE)
    cat(sprintf("t11_v02_expect <- %.2f\n", t11_v02), file=evf, append=TRUE)
  }
  else {
    expect_true(isTRUE(all.equal(t11_v01_expect, t11_v01, tolerance = 1.0e-4)))
    expect_true(isTRUE(all.equal(t11_v02_expect, t11_v02, tolerance = 1.0e-2)))
  }
})

#
# Test parameter errors
#
egraph <- ''
test_that( 'igraph parameter error',
{
  expect_error( leiden_find_partition( egraph ) )
})

inimem <- inimem <- as.integer( seq( 1, 1400 ) )
test_that( 'initial_membership parameter error',
{
  expect_error( leiden_find_partition( igraph, initial_membership = inimem, resolution_parameter = 0.5 ) )
})

edgwgt <- as.double( rep( 1.0, 61630 ) )
test_that( 'edge_weights parameter error',
{
  expect_error( leiden_find_partition( igraph, edge_weights = edgwgt, resolution_parameter = 0.5 ) )
})

nodsiz <- inimem <- as.integer( seq( 1, 1400 ) )
test_that( 'node_sizes parameter error',
{
  expect_error( leiden_find_partition( igraph, node_sizes = nodsiz, resolution_parameter = 0.5 ) )
})

test_that( 'resolution_parameter parameter error',
{
  expect_error( leiden_find_partition( igraph, resolution_parameter = 0.0 ) )
})

test_that( 'num_iter parameter error',
{
  expect_error( leiden_find_partition( igraph, num_iter = 0, resolution_parameter = 0.5 ) )
})

