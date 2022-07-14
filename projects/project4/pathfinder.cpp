#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "Maze.hpp"
#include "Problem.hpp"
#include "dynamic_array_list.hpp"
#include "queue.hpp"

using namespace std;

// global vars
State Fail_State {-1,-1};

// fcns
State breadthFirstSearch(Problem);


int main(int argc, char *argv[])
{
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
  cout << endl;

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
  cout
  State sln = breadthFirstSearch(p);
  cout << "Found Solution at (" << sln.rpos << "," << sln.cpos << ")" << endl;
  image(sln.rpos,sln.cpos) = GREEN;

  /* ============================================================================================================= */
  // Write solution image to file
  writeToFile(image, output_file);
  cout << "\nAll Good :D\n" << endl;
}

/** conducts a BFS
 * @param problem problem object containing maze object, present state, and a list of goal states
 * @return solution state 
 * @note state is stored internally (problem object) */
State breadthFirstSearch(Problem problem)
{
  // check initial state
  if(problem.goal())
    return problem.initial();

  // intialize frontier queue and explored vector
  Queue< State, DynamicArrayList<State> > frontier;
  vector<State> explored;

  // add initial value to frontier
  frontier.enqueue(problem.initial());

  // loop
  while(!frontier.isEmpty()){
    problem.setState(frontier.peekFront());
    frontier.dequeue();
    if(problem.goal())
      return problem.getState();
    explored.push_back(problem.getState());
    for(State next : problem.actions()){
      bool isExplored = false;
      for(State exp : explored)
        isExplored = isExplored || exp == next;
      if(!isExplored)
        frontier.enqueue(next);
    }
  }

  // if frontier is empty, all states are explored with no solution --> return failure
  return Fail_State;
}