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

#include "ResolutionParameterVertexPartition.h"

ResolutionParameterVertexPartition::ResolutionParameterVertexPartition(Graph* graph,
      vector<size_t> membership, double resolution_parameter) :
        MutableVertexPartition(graph,
        membership)
{ this->resolution_parameter = resolution_parameter; }

ResolutionParameterVertexPartition::ResolutionParameterVertexPartition(Graph* graph,
      vector<size_t> membership) :
        MutableVertexPartition(graph,
        membership)
{ this->resolution_parameter = 1.0; }

ResolutionParameterVertexPartition::ResolutionParameterVertexPartition(Graph* graph,
  double resolution_parameter) :
        MutableVertexPartition(graph)
{ this->resolution_parameter = resolution_parameter;  }

ResolutionParameterVertexPartition::ResolutionParameterVertexPartition(Graph* graph) :
        MutableVertexPartition(graph)
{ this->resolution_parameter = 1.0;  }

ResolutionParameterVertexPartition::~ResolutionParameterVertexPartition()
{ }
