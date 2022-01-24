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
# part = leidenalg.find_partition(g, partition_type=leidenalg.RBConfigurationVertexPartition, n_iterations=2, resolution_parameter=0.5, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.RBERVertexPartition, n_iterations=2, resolution_parameter=0.5, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.SignificanceVertexPartition, n_iterations=2, eed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.SurpriseVertexPartition, n_iterations=2, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.ModularityVertexPartition, n_iterations=2, seed=2016)

print(part)

ncomm = len(part)

print()
print('Quality: %f ' % (part.quality()))
print('Total weight in all communities: %f' % (part.total_weight_in_all_comms()))
print('Significance: %f ' % (leidenalg.SignificanceVertexPartition.FromPartition(part).quality()))
print()

print('Edge weight within community')
for i in range(ncomm):
  print('%.0f' % part.total_weight_in_comm(i), end=' ')
print()
print()

print('Edge weight from community')
for i in range(ncomm):
  print('%.0f' % part.total_weight_from_comm(i), end=' ')
print()
print()

print('Edge weight to community')
for i in range(ncomm):
  print('%.0f' % part.total_weight_to_comm(i), end=' ')
print()
