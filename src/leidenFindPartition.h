/* leidenFindPartition.h */

/*
 *   Leidenalg find partition R-C interface.
 *   Copyright (C) 2019  Cole Trapnell <coletrap@uw.edu>
 *   University of Washington, Genome Sciences Department, Seattle, WA
 *
 *  This file is free software: you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free Software
 *  Foundation, either version 3 of the License, or (at your option) any later
 *  version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *  PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with
 *  this program. If not, see http://www.gnu.org/licenses/.
 */

#ifndef LEIDENFINDPARTITION_H_
#define LEIDENFINDPARTITION_H_

#include <string>

int leidenFindPartition( igraph_t *igraph,
                           std::string partition_type,
                           std::vector<size_t> const* pinitialMembership,
                           std::vector<double> const* pedgeWeights,
                           std::vector<size_t> const* pnodeSizes,
                           size_t seed,
                           double resolutionParameter,
                           int numIter,
                           std::vector<size_t> *pmembership,
                           std::vector < double > *pcommunityModularity,
                           double *pquality,
                           int *fstatus );

#endif /* LEIDENFINDPARTITION_H_ */
