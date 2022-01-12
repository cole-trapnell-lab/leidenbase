#!/usr/bin/env python3

import sys
import platform
import leidenalg
import igraph as ig

print('python version info: %s' % ( platform.python_version() ) )
#print('leidenalg version: %s' % ( leidenalg.__version__ ) )
print('igraph version: %s' % ( ig.__version__ ) )

g = ig.read( filename='edgelist.edg', format='edgelist', directed=False)

part = leidenalg.find_partition(g, partition_type=leidenalg.CPMVertexPartition, n_iterations=2, resolution_parameter=0.5, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.CPMVertexPartition, n_iterations=2)
print(part)

