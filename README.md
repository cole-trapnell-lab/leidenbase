# Leidenbase

An R to C interface that runs the Leiden community detection algorithm to find a basic partition. It is the equivalent of the find_partition() function that is given in the Leidenalg distribution file 'leiden/src/functions.py' and includes the underlying Leidenalg C++ source code files of Leidenalg release version 0.7.0. The Leiden algorithm is described in

> *From Louvain to Leiden: guaranteeing well-connected communities.*  
   V. A. Traag, L. Waltman, and N. J. van Eck,  
   Scientific Reports (2019), DOI: 10.1038/s41598-019-41695-z  


## Getting Started

### Prerequisites

This distribution requires the C igraph library and the R igraph package.  

The C igraph library is available from  

  https://igraph.org/c/#downloads  

By default, the C igraph library installs in the directory */usr/local*. If you do not have permission to install it in the default location, we suggest that you install it in your home directory, which you can find using the command *echo $HOME*.


### Installing
  
#### Installing from R
  
Run the install.packages() function.
  
```
> install.packages('leidenbase')
```
  
If the C igraph library is installed in your home directory rather than */usr/local*, use the command

```
> install.packages('leidenbase',configure.args='--with-igraph=<home_directory>')
```

where <home_directory> is your home directory path.
  
#### Installing from the command line

Run the R INSTALL command.  
  
```
$ R CMD INSTALL leidenbase_0.1.0.tar.gz
```

If the C igraph library is installed in your home directory rather than */usr/local*, use the command  

```
$ R CMD INSTALL leidenbase_0.1.0.tar.gz --configure-args=--with-igraph=$HOME
```

#### Example commands for installing leidenbase and the C igraph library in your home directory

The following commands will install the C igraph library and leidenbase after you download the leidenbase distribution file to your home directory. (You may need to edit the versions in the distribution names.)  
  
  
```
cd ~
wget https://igraph.org/nightly/get/c/igraph-0.7.1.tar.gz
tar xzvf igraph-0.7.1.tar.gz
cd igraph-0.7.1
./configure --prefix=$HOME
make
make check
make install
cd ~
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/lib
R CMD INSTALL leidenbase_0.1.0.tar.gz --configure-args=--with-igraph=$HOME
```
  
You will need to add the line *export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:\$HOME/lib* to your shell startup script, which is, *$HOME/.bashrc*, if you use the bash shell.  
  
### Leidenbase functions

The R wrapper for running the Leiden algorithm find partition function is  

    leiden_find_partition <- function( igraph,
                               partition_type = c( 'RBConfigurationVertexPartition',
                                                   'CPMVertexPartition',
                                                   'ModularityVertexPartition',
                                                   'RBERVertexPartition',
                                                   'SignificanceVertexPartition',
                                                   'SurpriseVertexPartition' ),
                               initial_membership = NULL,
                               edge_weights = NULL,
                               node_sizes = NULL,
                               seed = NULL,
                               resolution_parameter = 0.5,
                               num_iter = 2 )

The C++ wrapper for running the Leiden algorithm find partition function
is  


    int leidenFindPartition( igraph_t *pigraph,
                             std::string const partitionType,
                             std::vector < size_t > const *pinitialMembership,
                             std::vector < double > const *pedgeWeights,
                             std::vector < size_t > const *pnodeSizes,
                             size_t seed,
                             double resolutionParameter,
                             int numIter,
                             std::vector < size_t > *pmembership,
                             std::vector < double > *pcommunityModularity,
                             double *pquality,
                             int *pstatus )`


## Licenses

The source code files and their sources are

| Source | License | Filename |
|:------|:------|:------|
| R igraph       | GPL-2+    | src/igraph_rinterface.(cpp\|h) [^1] |
| Leidenalg      | GPL-3+    | src/CPMVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/GraphHelper.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/LinearResolutionParameterVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/ModularityVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/MutableVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/Optimiser.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/RBConfigurationVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/RBERVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/ResolutionParameterVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/SignificanceVertexPartition.(cpp\|h) |
| Leidenalg      | GPL-3+    | src/SurpriseVertexPartition.(cpp\|h) |
| Trapnell Lab.  | GPL-3+    | src/leidenFindPartition.(cpp\|h) |
| Trapnell Lab.  | GPL-3+    | src/leidenFindPartitionR2C.cpp |
| Trapnell Lab.  | GPL-3+    | R/leidenbase.R |

[^1]: The igraph_rinterface.cpp file consists of two functions pulled from the R igraph src/rinterface.cpp file.

## Acknowledgements

We express our gratitude to the authors of the igraph and Leidenalg packages for designing, writing, and making them freely available as source code.


