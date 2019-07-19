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

#ifndef RESOLUTIONPARAMETERVERTEXPARTITION_H
#define RESOLUTIONPARAMETERVERTEXPARTITION_H

#include <MutableVertexPartition.h>

class ResolutionParameterVertexPartition : public MutableVertexPartition
{
  public:
    ResolutionParameterVertexPartition(Graph* graph,
          vector<size_t> membership, double resolution_parameter);
    ResolutionParameterVertexPartition(Graph* graph,
          vector<size_t> membership);
    ResolutionParameterVertexPartition(Graph* graph, double resolution_parameter);
    ResolutionParameterVertexPartition(Graph* graph);
    virtual ~ResolutionParameterVertexPartition();

    double resolution_parameter;

    virtual double quality()
    {
      return this->quality(this->resolution_parameter);
    };

    virtual double quality(double resolution_parameter)
    {
      throw Exception("Function not implemented. This should be implented in a derived class, since the base class does not implement a specific method.");
    };

  private:

};

#endif // RESOLUTIONPARAMETERVERTEXPARTITION_H
