#!/usr/bin/env python3

import sys
import platform
import leidenalg
import igraph as ig

def read_edge_weights():
  fp = open('edge_weights.txt', 'r')
  w = fp.read().splitlines()
  fp.close()
  v = [0] * len(w)
  for i in range(len(w)):
    v[i] = float(w[i])
  return(v)

def read_initial_memberships():
  fp = open('initial_memberships.txt', 'r')
  w = fp.read().splitlines()
  fp.close()
  m = [0] * len(w)
  for i in range(len(w)):
    m[i] = int(w[i])
  return(m)


edge_wghts = read_edge_weights()
init_members = read_initial_memberships()

print('python version info: %s' % ( platform.python_version() ) )
print('leidenalg version: %s' % ( leidenalg.version ) )
print('igraph version: %s' % ( ig.__version__ ) )

g = ig.read( filename='edgelist.edg', format='edgelist', directed=False)

# leidenalg.find_partition(graph, partition_type, initial_membership=None, weights=None, n_iterations=2, max_comm_size=0, seed=None, **kwargs)¶
# part = leidenalg.find_partition(g, partition_type=leidenalg.RBConfigurationVertexPartition, initial_membership=init_members, weights=edge_wghts, n_iterations=2, resolution_parameter=0.5, seed=2016)


# part = leidenalg.find_partition(g, partition_type=leidenalg.CPMVertexPartition, n_iterations=2, resolution_parameter=0.5, seed=2016)
part = leidenalg.find_partition(g, partition_type=leidenalg.RBConfigurationVertexPartition, n_iterations=2, resolution_parameter=0.5, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.RBERVertexPartition, n_iterations=2, resolution_parameter=0.5, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.SignificanceVertexPartition, n_iterations=2, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.SurpriseVertexPartition, n_iterations=2, seed=2016)
# part = leidenalg.find_partition(g, partition_type=leidenalg.ModularityVertexPartition, n_iterations=2, seed=2016)

print(part)

ncomm = len(part)

print()
print('Quality: %.0f ' % (part.quality()))
print('Significance: %.0f ' % (leidenalg.SignificanceVertexPartition.FromPartition(part).quality()))
print('Total weight in all communities: %.0f' % (part.total_weight_in_all_comms()))
print('Apparently the total weight in all communities is the sum of the edge')
print('weights in communities.')
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


