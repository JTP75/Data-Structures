#include "adjacency_matrix_graph.hpp"
#include <algorithm>

using namespace std;

template <typename LabelType>
AdjacencyMatrixGraph<LabelType>::AdjacencyMatrixGraph()
{
}

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumVertices() const
{
    return vertices.size();
}

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumEdges() const
{
    size_t ne = 0;
    for(vector<bool> v : edges)
        for(bool b : v)
            if(b)
                ne++;
    return ne;

}
        
template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::add(LabelType start, LabelType end)
{
    // find idcs of start and end, if they exist
    long start_idx = -1, end_idx = -1;
    for(size_t i=0; i < vertices.size(); i++){
        if(vertices[i] == start)
            start_idx = i;
        if(vertices[i] == end)
            end_idx = i;
    }
    if(start_idx == end_idx && start_idx != -1){
        std::cerr << "start/end vertices must be different" << std::endl;
        return false;
    }
    // add new vertices if necessary
    if(start_idx == -1){
        vertices.push_back(start);
        vector<bool> v;
        for(size_t i=0; i < vertices.size()-1; i++){
            edges[i].push_back(false);
            v.push_back(false);
        }
        v.push_back(false);
        edges.push_back(v);
        start_idx = vertices.size()-1;
    }
    if(end_idx == -1){
        vertices.push_back(end);
        vector<bool> v;
        for(size_t i=0; i < vertices.size()-1; i++){
            edges[i].push_back(false);
            v.push_back(false);
        }
        v.push_back(false);
        edges.push_back(v);
        end_idx = vertices.size()-1;
    }
    // add edge
    if(start_idx < end_idx){
        if(edges[start_idx][end_idx]){
            std::cerr << "edge already exists" << std::endl;
            return false;
        }
        edges[start_idx][end_idx] = true;
    }
    else{
        if(edges[end_idx][start_idx]){
            std::cerr << "edge already exists" << std::endl;
            return false;
        }
        edges[end_idx][start_idx] = true;
    }

    return true;
}
template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::remove(LabelType start, LabelType end)
{
    // find idcs of start and end, if they exist
    long start_idx = -1, end_idx = -1;
    for(size_t i=0; i < vertices.size(); i++){
        if(vertices[i] == start)
            start_idx = i;
        if(vertices[i] == end)
            end_idx = i;
    }
    if(start_idx == -1 || end_idx == -1){
        std::cerr << "start or end value not found" << std::endl;
        return false;
    }
    else if(start_idx == end_idx){
        std::cerr << "start/end vertices must be different" << std::endl;
        return false;
    }
    // remove edge
    if(start_idx < end_idx){
        if(!edges[start_idx][end_idx]){
            std::cerr << "edge doesnt exist" << std::endl;
            return false;
        }
        edges[start_idx][end_idx] = false;
    }
    else{
        if(!edges[end_idx][start_idx]){
            std::cerr << "edge doesnt exist" << std::endl;
            return false;
        }
        edges[end_idx][start_idx] = false;
    }
    // remove lone vertices
    if(isLone(start_idx)){
        vertices.erase(vertices.begin() + start_idx);
        for(size_t i = 0; i < vertices.size()-1; i++)
            edges[i].erase(edges[i].begin() + start_idx);
        edges.erase(edges.begin() + start_idx);
    }
    if(isLone(end_idx)){
        vertices.erase(vertices.begin() + end_idx);
        for(size_t i = 0; i < vertices.size()-1; i++)
            edges[i].erase(edges[i].begin() + end_idx);
        edges.erase(edges.begin() + end_idx);
    }

    return true;
}

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::isLone(size_t idx) const
{
    for(size_t i=0; i < vertices.size(); i++)
        if(edges[idx][i])
            return false;
    return true;
}