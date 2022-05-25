#ifndef _ADJACENCY_MATRIX_GRAPH_H_
#define _ADJACENCY_MATRIX_GRAPH_H_

#include "abstract_graph.hpp"

template <typename LabelType>
class AdjacencyMatrixGraph: public AbstractGraph<LabelType>
{
    public:

        AdjacencyMatrixGraph();

        int getNumVertices() const;
        
        int getNumEdges() const;

        bool add(LabelType start, LabelType end);

        bool remove(LabelType start, LabelType end);

        void depthFirstTraversal(LabelType start, void visit(LabelType&));

        void breadthFirstTraversal(LabelType start, void visit(LabelType&));
  
};

#include "adjacency_matrix_graph.tpp"

#endif 
