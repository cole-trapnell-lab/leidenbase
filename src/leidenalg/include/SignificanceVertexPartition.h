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

#ifndef SIGNIFICANCEVERTEXPARTITION_H
#define SIGNIFICANCEVERTEXPARTITION_H

#include <MutableVertexPartition.h>


class SignificanceVertexPartition : public MutableVertexPartition
{
  public:
    SignificanceVertexPartition(Graph* graph, vector<size_t> const& membership);
    SignificanceVertexPartition(Graph* graph);
    virtual ~SignificanceVertexPartition();
    virtual SignificanceVertexPartition* create(Graph* graph);
    virtual SignificanceVertexPartition* create(Graph* graph, vector<size_t> const& membership);

    virtual double diff_move(size_t v, size_t new_comm);
    virtual double quality();
  protected:
  private:
};

#endif // SIGNIFICANCEVERTEXPARTITION_H
