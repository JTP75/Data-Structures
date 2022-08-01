#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "adjacency_matrix_graph.hpp"
typedef AdjacencyMatrixGraph<int> GraphType;

TEST_CASE("Test Construction", "[construction]") {
  GraphType g;
  REQUIRE(g.getNumVertices() == 0);
  REQUIRE(g.getNumEdges() == 0);
}
TEST_CASE("Test add", "[add]") {
  GraphType g;

  REQUIRE(g.add(0,1));          // two new vertices
  REQUIRE(g.add(1,2));          // one new vertex
  REQUIRE(g.add(2,0));          // no new vertices
  REQUIRE(g.add(4,3));          // disconnected vertices
  REQUIRE_FALSE(g.add(1,2));    // existing edge

  REQUIRE(g.getNumVertices() == 5);
  REQUIRE(g.getNumEdges() == 4);
}
TEST_CASE("Test remove", "[remove]") {
  GraphType g;

  g.add(1,0);
  g.add(1,2);
  g.add(2,3);
  g.add(4,3);
  g.add(0,4);
  g.add(2,20);

  REQUIRE_FALSE(g.remove(0,20));    // non-existant edge
  REQUIRE(g.remove(2,1));           // no vertices removed

  REQUIRE(g.getNumVertices() == 6);
  REQUIRE(g.getNumEdges() == 5);

  REQUIRE(g.remove(0,1));           // 1 vertex removed (1)

  REQUIRE(g.getNumVertices() == 5);
  REQUIRE(g.getNumEdges() == 4);

  REQUIRE(g.remove(2,3));
  REQUIRE(g.remove(20,2));          // 2 vertices removed (2 and 20)

  REQUIRE(g.getNumVertices() == 3);
  REQUIRE(g.getNumEdges() == 2);
}

/*
  F T T F F F
  F F F F T F
  F F F T F T
  F F F F T F
  F F F F F F
  F F F F F F

  1 0 2 3 4 20
*/