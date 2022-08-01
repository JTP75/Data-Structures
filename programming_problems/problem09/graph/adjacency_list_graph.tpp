#include "adjacency_list_graph.hpp"
#include <algorithm>

using namespace std;

template <typename LabelType>
AdjacencyListGraph<LabelType>::AdjacencyListGraph()
{
}

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumVertices() const
{
    return list.size();
}

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumEdges() const
{
    size_t sum = 0;
    for(AdjacencyListItem entry : list)
        entry.adjacencies.size();
    return sum/2;           // due to the structure of ADT, each edge is counted twice
}
        
template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::add(LabelType start, LabelType end)
{
    if(start == end){
        cerr << "In AdjancencyListGraph<LabelType>::add() : self connections not allowed" << endl;
        return false;
    }
    long start_idx = -1, end_idx = -1;
    for(size_t i=0; i < list.size(); i++){
        if(list[i].item == start)
            start_idx = i;
        if(list[i].item == end)
            end_idx = i;
    }
    
    if(start_idx == -1){
        AdjacencyListItem<LabelType> entry;
        entry.item = start;
        list.push_back(entry);
        start_idx = list.size() - 1;
    }
    if(end_idx == -1){
        AdjacencyListItem<LabelType> entry;
        entry.item = end;
        list.push_back(entry);
        end_idx = list.size() - 1;
    }
    if(
        find(list[start_idx].adjacencies.begin(),list[start_idx].adjacencies.end(),end) != list[start_idx].adjacencies.end() ||
        find(list[end_idx].adjacencies.begin(),list[end_idx].adjacencies.end(),start) != list[end_idx].adjacencies.end() 
    ){
        cerr << "In AdjancencyListGraph<LabelType>::add() : connection already exists" << endl;
        return false;
    }
    list[start_idx].adjacencies.push_back(end);
    list[end_idx].adjacencies.push_back(start);
}

template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::remove(LabelType start, LabelType end)
{

}

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}