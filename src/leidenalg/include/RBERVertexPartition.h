/*
 *  Licence
 *  -------
 *
 *  Copyright (C) 2016 V.A. Traag
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

#ifndef RBERVERTEXPARTITION_H
#define RBERVERTEXPARTITION_H

#include <LinearResolutionParameterVertexPartition.h>


class RBERVertexPartition : public LinearResolutionParameterVertexPartition
{
  public:
    RBERVertexPartition(Graph* graph,
          vector<size_t> const& membership, double resolution_parameter);
    RBERVertexPartition(Graph* graph,
          vector<size_t> const& membership);
    RBERVertexPartition(Graph* graph,
      double resolution_parameter);
    RBERVertexPartition(Graph* graph);
    virtual ~RBERVertexPartition();
    virtual RBERVertexPartition* create(Graph* graph);
    virtual RBERVertexPartition* create(Graph* graph, vector<size_t> const& membership);

    virtual double diff_move(size_t v, size_t new_comm);
    virtual double quality(double resolution_parameter);

  protected:
  private:
};

#endif // RBERVERTEXPARTITION_H
