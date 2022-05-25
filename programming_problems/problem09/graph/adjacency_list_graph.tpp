#include "adjacency_list_graph.hpp"

template <typename LabelType>
AdjacencyListGraph<LabelType>::AdjacencyListGraph() {}

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumVertices() const {}

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumEdges() const {}
        
template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::add(LabelType start, LabelType end) {}   

template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::remove(LabelType start, LabelType end) {}

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}