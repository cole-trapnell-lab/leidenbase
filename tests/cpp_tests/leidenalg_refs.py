#!/usr/bin/env python3

import sys
import platform
import leidenalg
import igraph as ig


def read_edge_weights(weights_file):
  fp = open(weights_file, 'r')
  w = fp.read().splitlines()
  fp.close()
  v = [0] * len(w)
  for i in range(len(w)):
    v[i] = float(w[i])
  return(v)


def read_initial_memberships(membership_file):
  fp = open(membership_file, 'r')
  w = fp.read().splitlines()
  fp.close()
  m = [0] * len(w)
  for i in range(len(w)):
    m[i] = int(w[i])
  return(m)


def get_partition_type(partition_type_name):
  if(partition_type_name == 'CPMVertexPartition'):
    partition_type = leidenalg.CPMVertexPartition
  elif(partition_type_name == 'RBConfigurationVertexPartition'):
    partition_type = leidenalg.RBConfigurationVertexPartition
  elif(partition_type_name == 'RBERVertexPartition'):
    partition_type = leidenalg.RBERVertexPartition
  elif(partition_type_name == 'SignificanceVertexPartition'):
    partition_type = leidenalg.SignificanceVertexPartition
  elif(partition_type_name == 'SurpriseVertexPartition'):
    partition_type = leidenalg.SurpriseVertexPartition
  elif(partition_type_name == 'ModularityVertexPartition'):
    partition_type = leidenalg.ModularityVertexPartition
  else:
    print('Error: get_partition_type: unknown partition type: %s' % (partition_type_name))
  return(partition_type)


def print_comm_info(partition_type_name, part):
  print('python version info: %s' % (platform.python_version()))
  print('igraph version: %s' % (ig.__version__ ))
  print('leidenalg version: %s' % (leidenalg.version))
  print()
  print('==== partition type: %s' % (partition_type_name))
  print()

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


def write_comm_file(edgelist_file=None, weights_file=None, membership_file=None, partition_type_name=None, directed=None, resolution_parameter=None, n_iterations=None, seed=None, part=None, outname_root=None):
  fp = open(outname_root, 'w+')
  
  n_node = len(part.membership)
  n_comm = len(part)

  print('python_version <- \'%s\'' % (platform.python_version()), file=fp)
  print('igraph_version <- \'%s\'' % (ig.__version__), file=fp)
  print('leidenalg_version <- \'%s\'' % (leidenalg.version), file=fp)
  print(file=fp)

  print('leidenalg_edgelist_file <- \'%s\'' % (edgelist_file), file=fp)
  print('leidenalg_weights_file <- \'%s\'' % (weights_file if(weights_file != None) else 'NULL'), file=fp)
  print('leidenalg_membership_file <- \'%s\'' % (membership_file if(membership_file != None) else 'NULL'), file=fp)
  print(file=fp)

  print('leidenalg_graph_directed <- %s' % ('TRUE' if(directed == True) else 'FALSE'), file=fp)
  print('leidenalg_partition_type <- \'%s\'' % (partition_type_name), file=fp)
  print('leidenalg_resolution_parameter <- %f' % (resolution_parameter), file=fp)
  print('leidenalg_n_iterations <- %d' % (n_iterations), file=fp)
  print('leidenalg_seed <- %d' % (seed), file=fp)
  print(file=fp)
  print('leidenalg_n_node <- %d' % (n_node), file=fp)
  print('leidenalg_n_comm <- %d' % (n_comm), file=fp)
  print('leidenalg_quality <- %.2f' % (part.quality()), file=fp)
  print('leidenalg_modularity <- %.4f' % (part.modularity), file=fp)
  print('leidenalg_significance <- %.2f' % (leidenalg.SignificanceVertexPartition.FromPartition(part).quality()), file=fp)
  print('leidenalg_tot_weight_in_all_comms <- %.2f' % (part.total_weight_in_all_comms()), file=fp)
  print(file=fp)

  print('leidenalg_membership <- c(', file=fp)
  for i in range(n_node-1):
    print('%d, ' % (part.membership[i]+1), end='', file=fp)
    if((i+1) % 25 == 0):
      print(file=fp)
  print('%d)' % (part.membership[n_node-1]+1), file=fp)
  print(file=fp)

  print('leidenalg_edge_weight_in_comm <- c(', end='', file=fp)
  for i in range(n_comm-1):
    print('%.0f, ' % (part.total_weight_in_comm(i)), end='', file=fp)
  print('%.0f)' % (part.total_weight_in_comm(n_comm-1)), file=fp)
  print(file=fp)

  print('leidenalg_edge_weight_from_comm <- c(', end='', file=fp)
  for i in range(n_comm-1):
    print('%.0f, ' % (part.total_weight_from_comm(i)), end='', file=fp)
  print('%.0f)' % (part.total_weight_from_comm(n_comm-1)), file=fp)
  print(file=fp)

  print('leidenalg_edge_weight_from_comm <- c(', end='', file=fp)
  for i in range(n_comm-1):
    print('%.0f, ' % (part.total_weight_from_comm(i)), end='', file=fp)
  print('%.0f)' % (part.total_weight_from_comm(n_comm-1)), file=fp)
  print(file=fp)

  fp.close()


def write_call_leidenbase(fp):
  print('run_leidenbase <- function(part) {', file=fp)
  print('  library(igraph)', file=fp)
  print('  library(leidenbase)', file=fp)
  print('  graph <- read_graph(part$edgelist_file, format=\'edgelist\', directed=part$graph_directed)', file=fp)
  print('  if(!is.null(part$membership_file))', file=fp)
  print('    initial_membership <- as.numeric(read.table(part$membership_file)$V1)', file=fp)
  print('  else', file=fp)
  print('    initial_membership <- NULL', file=fp)
  print('  if(!is.null(part$weights_file))', file=fp)
  print('    edge_weights <- as.numeric(read.table(part$weights_file)$V1)', file=fp)
  print('  else', file=fp)
  print('    edge_weights <- NULL', file=fp)
  print('  comm <- leiden_find_partition(graph, partition_type=part$partition_type, initial_membership=initial_membership, edge_weights=edge_weights, seed=part$seed, resolution_parameter=part$resolution_parameter, num_iter=part$n_iterations)', file=fp)
  print('}', file=fp)
  print(file=fp)


def write_cmp_comms(fp):
  print('cmp_comms <- function(leidenalg_part) {', file=fp)
  print('  leidenbase_part <- run_leidenbase(leidenalg_part)', file=fp)

  print('  message(\'Test if community attributes are the same\')', file=fp)
  print('  message(\'  comm memberships: \', setequal(leidenbase_part$membership, leidenalg_part$membership))', file=fp)
  print('  message(\'  compare comm edge weight in community: \', setequal(round(leidenbase_part$edge_weight_within_community), leidenalg_part$edge_weight_in_comm))', file=fp)
  print('  message(\'  compare comm edge weight from community: \', setequal(round(leidenbase_part$edge_weight_from_community), leidenalg_part$edge_weight_from_comm))', file=fp)
  print('  message(\'  compare comm edge weight to community: \', setequal(round(leidenbase_part$edge_weight_to_community), leidenalg_part$edge_weight_to_comm))', file=fp)
  print('  message(\'Quality values: leidenalg: \', leidenalg_part$quality, \'  leidenbase: \', leidenbase_part$quality)', file=fp)
  # the significance is defined only for unweighted graphs according to leidenalg
  print('  if(is.null(leidenalg_part$weights_file))', file=fp)
  print('    message(\'Significance values: leidenalg: \', leidenalg_part$significance, \'  leidenbase: \', leidenbase_part$significance)', file=fp)
  print('  message(\'Modularity values: leidenalg: \', leidenalg_part$modularity, \'  leidenbase: \', leidenbase_part$modularity)', file=fp)
  print('}', file=fp)


def write_comm_file_as_list(edgelist_file=None, weights_file=None, membership_file=None, partition_type_name=None, directed=None, resolution_parameter=None, n_iterations=None, seed=None, part=None, outname_root=None):
  fnam = outname_root + '.R'
  fp = open(fnam, 'w+')

  n_node = len(part.membership)
  n_comm = len(part)

  print('# In R, source this file and run \'cmp_comms(leidenalg_part)\'', file=fp)
  print('#', file=fp)
  print('leidenalg_part <- list(', file=fp)
  print('python_version=\'%s\',' % (platform.python_version()), file=fp)
  print('igraph_version=\'%s\',' % (ig.__version__), file=fp)
  print('version=\'%s\',' % (leidenalg.version), file=fp)

  print('edgelist_file=\'%s\',' % (edgelist_file), file=fp)
  if(weights_file != None):
    print('weights_file=\'%s\',' % (weights_file if(weights_file != None) else 'NULL'), file=fp)
  else:
    print('weights_file=NULL,', file=fp)
  if(membership_file != None):
    print('membership_file=\'%s\',' % (membership_file if(membership_file != None) else 'NULL'), file=fp)
  else:
    print('membership_file=NULL,', file=fp)
  print('graph_directed=%s,' % ('TRUE' if(directed == True) else 'FALSE'), file=fp)
  print('partition_type=\'%s\',' % (partition_type_name), file=fp)
  print('resolution_parameter=%f,' % (resolution_parameter), file=fp)
  print('n_iterations=%d,' % (n_iterations), file=fp)
  print('seed=%d,' % (seed), file=fp)

  print('n_node=%d,' % (n_node), file=fp)
  print('n_comm=%d,' % (n_comm), file=fp)
  print('quality=%.2f,' % (part.quality()), file=fp)
  print('modularity=%.4f,' % (part.modularity), file=fp)
  print('significance=%.2f,' % (leidenalg.SignificanceVertexPartition.FromPartition(part).quality()), file=fp)
  print('tot_weight_in_all_comms=%.2f,' % (part.total_weight_in_all_comms()), file=fp)

  print('membership=c(', file=fp)
  for i in range(n_node-1):
    print('%d, ' % (part.membership[i]+1), end='', file=fp)
  print('%d),' % (part.membership[n_node-1]+1), file=fp)

  print('edge_weight_in_comm=c(', end='', file=fp)
  for i in range(n_comm-1):
    print('%.0f, ' % (part.total_weight_in_comm(i)), end='', file=fp)
  print('%.0f),' % (part.total_weight_in_comm(n_comm-1)), file=fp)

  print('edge_weight_from_comm=c(', end='', file=fp)
  for i in range(n_comm-1):
    print('%.0f, ' % (part.total_weight_from_comm(i)), end='', file=fp)
  print('%.0f),' % (part.total_weight_from_comm(n_comm-1)), file=fp)

  print('edge_weight_to_comm=c(', end='', file=fp)
  for i in range(n_comm-1):
    print('%.0f, ' % (part.total_weight_to_comm(i)), end='', file=fp)
  print('%.0f)' % (part.total_weight_to_comm(n_comm-1)), file=fp)

  print(')', file=fp)
  print(file=fp)

  write_call_leidenbase(fp)

  write_cmp_comms(fp)

  fp.close()


def make_ref(edgelist_file=None,
             weights_file=None,
             membership_file=None,
             directed=False,
             partition_type_name=None,
             resolution_parameter=0.5,
             n_iterations=2,
             seed=2016,
             outname_root=None):

  graph = ig.read(filename=edgelist_file, format='edgelist', directed=directed)
  if(weights_file != None):
    edge_wghts = read_edge_weights(weights_file)
  else:
    edge_wghts = None
  if(membership_file != None):
    init_members = read_initial_memberships(membership_file)
  else:
    init_members = None

  partition_type = get_partition_type(partition_type_name)
#  part = leidenalg.find_partition(graph, partition_type=partition_type, initial_membership=init_members, weights=edge_wghts, n_iterations=n_iterations, resolution_parameter=resolution_parameter, seed=seed)
  if(partition_type_name != 'SignificanceVertexPartition' and partition_type_name != 'SurpriseVertexPartition' and partition_type_name != 'ModularityVertexPartition'):
    part = leidenalg.find_partition(graph, partition_type=partition_type, initial_membership=init_members, weights=edge_wghts, n_iterations=n_iterations, resolution_parameter=resolution_parameter, seed=seed)
  elif(partition_type_name == 'SignificanceVertexPartition'):
    part = leidenalg.find_partition(graph, partition_type=partition_type, initial_membership=init_members, n_iterations=n_iterations, seed=seed)
  else:
    part = leidenalg.find_partition(graph, partition_type=partition_type, initial_membership=init_members, weights=edge_wghts, n_iterations=n_iterations, seed=seed)

#  print_comm_info(partition_type_name, part)
  write_comm_file_as_list(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, partition_type_name=partition_type_name, directed=directed, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, part=part, outname_root=outname_root)



# weights_file = 'edge_weights.txt'
# membership_file = 'initial_memberships.txt'

# edgelist_file = 'edgelist.edg'
# weights_file = None
# membership_file = None
# directed = False
# partition_type_name = 'ModularityVertexPartition'
# resolution_parameter = 0.5
# n_iterations = 2
# seed = 2016
# outname_root = 'foo'

# make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)


## top

#test_start
test_name = 'test_1_1'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'CPMVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_1_1'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_1_2'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'ModularityVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_1_2'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_1_3'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'RBConfigurationVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_1_3'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_1_4'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'RBERVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_1_4'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_1_5'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'SignificanceVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_1_5'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_1_6'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'SurpriseVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_1_6'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)



#test_start
test_name = 'test_2_1'
edgelist_file = 'edgelist.edg'
weights_file:'edge_weights.txt'
membership_file:'initial_memberships.txt'
directed = False
partition_type_name = 'CPMVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_2_1'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_2_2'
edgelist_file = 'edgelist.edg'
weights_file:'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = False
partition_type_name = 'ModularityVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_2_2'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_2_3'
edgelist_file = 'edgelist.edg'
weights_file = 'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = False
partition_type_name = 'RBConfigurationVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_2_3'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_2_4'
edgelist_file = 'edgelist.edg'
weights_file = 'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = False
partition_type_name = 'RBERVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_2_4'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_2_5'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = 'initial_memberships.txt'
directed = False
partition_type_name = 'SignificanceVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_2_5'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_2_6'
edgelist_file = 'edgelist.edg'
weights_file = 'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = False
partition_type_name = 'SurpriseVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_2_6'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)


#test_start
test_name = 'test_3_1'
edgelist_file = 'edgelist.edg'
weights_file:'edge_weights.txt'
membership_file:'initial_memberships.txt'
directed = True
partition_type_name = 'CPMVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_3_1'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_3_2'
edgelist_file = 'edgelist.edg'
weights_file:'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = True
partition_type_name = 'ModularityVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_3_2'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_3_3'
edgelist_file = 'edgelist.edg'
weights_file = 'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = True
partition_type_name = 'RBConfigurationVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_3_3'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_3_4'
edgelist_file = 'edgelist.edg'
weights_file = 'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = True
partition_type_name = 'RBERVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_3_4'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_3_5'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = 'initial_memberships.txt'
directed = True
partition_type_name = 'SignificanceVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_3_5'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_3_6'
edgelist_file = 'edgelist.edg'
weights_file = 'edge_weights.txt'
membership_file = 'initial_memberships.txt'
directed = True
partition_type_name = 'SurpriseVertexPartition'
resolution_parameter = 0.5
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_3_6'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)



#test_start
test_name = 'test_4_1'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'CPMVertexPartition'
resolution_parameter = 0.1
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_4_1'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_4_2'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'ModularityVertexPartition'
resolution_parameter = 0.1
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_4_2'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_4_3'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'RBConfigurationVertexPartition'
resolution_parameter = 0.1
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_4_3'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_4_4'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'RBERVertexPartition'
resolution_parameter = 0.1
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_4_4'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_4_5'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'SignificanceVertexPartition'
resolution_parameter = 0.1
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_4_5'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_4_6'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'SurpriseVertexPartition'
resolution_parameter = 0.1
n_iterations = 2
seed = 2016
outname_root = 'tests_out/test_4_6'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)


#test_start
test_name = 'test_5_1'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'CPMVertexPartition'
resolution_parameter = 0.1
n_iterations = 3
seed = 2016
outname_root = 'tests_out/test_5_1'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_5_2'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'ModularityVertexPartition'
resolution_parameter = 0.1
n_iterations = 3
seed = 2016
outname_root = 'tests_out/test_5_2'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_5_3'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'RBConfigurationVertexPartition'
resolution_parameter = 0.1
n_iterations = 3
seed = 2016
outname_root = 'tests_out/test_5_3'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_5_4'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'RBERVertexPartition'
resolution_parameter = 0.1
n_iterations = 3
seed = 2016
outname_root = 'tests_out/test_5_4'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_5_5'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'SignificanceVertexPartition'
resolution_parameter = 0.1
n_iterations = 3
seed = 2016
outname_root = 'tests_out/test_5_5'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)

#test_start
test_name = 'test_5_6'
edgelist_file = 'edgelist.edg'
weights_file = None
membership_file = None
directed = False
partition_type_name = 'SurpriseVertexPartition'
resolution_parameter = 0.1
n_iterations = 3
seed = 2016
outname_root = 'tests_out/test_5_6'
#test_end
make_ref(edgelist_file=edgelist_file, weights_file=weights_file, membership_file=membership_file, directed=directed, partition_type_name=partition_type_name, resolution_parameter=resolution_parameter, n_iterations=n_iterations, seed=seed, outname_root=outname_root)


## bottom
