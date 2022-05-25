#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "adjacency_list_graph.hpp"

TEST_CASE("Test Construction", "[construction]") {
  AdjacencyListGraph<int>  listGraph;
  REQUIRE(listGraph.getNumVertices() == 0);
}

