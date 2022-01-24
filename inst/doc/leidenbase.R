## ----setup, echo=FALSE, results='hide', message=FALSE-------------------------
require(knitr)
opts_chunk$set(error=FALSE, message=FALSE, warning=FALSE)
library(leidenbase)
library(igraph)

## -----------------------------------------------------------------------------
library(igraph)
fpath <- system.file('testdata', 'igraph_n1500_edgelist.txt.gz', package='leidenbase')
zfp <- gzfile(fpath)
igraph <- read_graph(file = zfp, format='edgelist')
res <- leiden_find_partition(igraph, partition_type = 'CPMVertexPartition', seed = 123456, resolution_parameter = 0.5)

## -----------------------------------------------------------------------------
str(res)

## -----------------------------------------------------------------------------
head(res[['membership']])

## -----------------------------------------------------------------------------
which(res[['membership']]==1)

## -----------------------------------------------------------------------------
# lim1 <- max(res$membership)
lim1 <- 3
for( i in seq(lim1)) {
  cat(paste0('Community ', i, ':'))
  for(j in which(res[['membership']]==i))
    cat(' ', j)
  cat('\n')
}

