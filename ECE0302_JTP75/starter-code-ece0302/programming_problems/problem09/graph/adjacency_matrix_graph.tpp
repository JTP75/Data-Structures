#include "adjacency_matrix_graph.hpp"

template <typename LabelType>
AdjacencyMatrixGraph<LabelType>::AdjacencyMatrixGraph() {}

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumVertices() const {}

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumEdges() const {}
        
template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::add(LabelType start, LabelType end) {}   

template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::remove(LabelType start, LabelType end) {}

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}