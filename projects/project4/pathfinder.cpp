#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "Maze.hpp"
#include "Problem.hpp"
#include "dynamic_array_list.hpp"
#include "queue.hpp"

using namespace std;


int main(int argc, char *argv[])
{/*
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  string input_file = argv[1];
  string output_file = argv[2];
  /* ============================================================================================================= */

  string input_file = "tests/maze00.png";
  string output_file = "tests/output00.png";

  // Read input image from file
  Image<Pixel> image;
  try{
    image = readFromFile(input_file);
  }catch(std::runtime_error& err){
    cerr << "Error! Exception thrown by readFromFile(): " << err.what() << endl;
    throw err;
  }
  int rows = image.height();
  int cols = image.width();

  // check image is valid and construct maze
  try{
    Maze test(image);
  }catch(std::runtime_error err){
    return EXIT_FAILURE;
  }Maze maze(image);

  // problem object
  Problem p(maze);

  /* ============================================================================================================= */
  // Write solution image to file
  writeToFile(image, output_file);
  cout << "\nAll Good :D\n" << endl;
}
