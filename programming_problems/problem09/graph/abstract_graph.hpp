
#ifndef _ABSTRACT_GRAPH_H_
#define _ABSTRACT_GRAPH_H_

#include <cstdlib>

template <typename LabelType>
class AbstractGraph
{
public:
  // get number of vertices in the graph
  virtual int getNumVertices() const = 0;

  // get number of edges in the graph
  virtual int getNumEdges() const = 0;

  // create an undirected edge between two vertices with the provided labels
  // if vertices do not exist, create them and add them to the graph before adding the edge
  virtual bool add(LabelType start, LabelType end) = 0;

  // remove an edge from this graph
  // if a vertex is left with no other edges, remove it from the graph since this is a connected graph
  virtual bool remove(LabelType start, LabelType end) = 0;

  // perform a depth-first search of the graph beginning at the given vertex
  // call the provided function once for each vertex visited
  virtual void depthFirstTraversal(LabelType start, void visit(LabelType&)) = 0;

  // perform a breadth-first search of the graph beginning at the given vertex
  // call the provided function once for each vertex visited
  virtual void breadthFirstTraversal(LabelType start, void visit(LabelType&)) = 0;
};

#endif 
