#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "adjacency_matrix_graph.hpp"

TEST_CASE("Test Construction", "[construction]") {
  AdjacencyMatrixGraph<int>  matrixGraph;
  REQUIRE(matrixGraph.getNumVertices() == 0);
}
