#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "Maze.hpp"
#include "Problem.hpp"
#include "dynamic_array_list.hpp"
#include "queue.hpp"
#include <time.h>

using namespace std;

// typedefs
typedef Queue< State, DynamicArrayList<State> > StateQueue;

// global vars
State Fail_State {-1,-1};

// fcns
void enqueue(StateQueue &, Problem &, State);
State breadthFirstSearch(Problem, vector<State> &);


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
  cout << "Maze size: h = " << maze.h() << ", w = " << maze.w() << endl;
  cout << "Start position: (" << p.initial().rpos << "," << p.initial().cpos << ")" << endl;

  vector<State> explored;
  State sln = breadthFirstSearch(p, explored);

  if(sln != Fail_State){
    cout << "\nFound Solution at (" << sln.rpos << "," << sln.cpos << ")" << endl;
    for(State s : explored)
      image(s.rpos,s.cpos) = BLUE;      // color all explored states blue
    image(sln.rpos,sln.cpos) = GREEN;
    image(p.initial().rpos,p.initial().cpos) = RED;
  }else{
    cout << "\nNo solution found" << endl;
    for(State s : explored)
      image(s.rpos,s.cpos) = BLUE;
    image(p.initial().rpos,p.initial().cpos) = RED;
  }

  /* ============================================================================================================= */
  // Write solution image to file
  writeToFile(image, output_file);
  cout << "\nAll Good :D\n" << endl;
}

/** enqueue function: performs additional tasks 
 * marks each mazesquare if its state is added to the frontier and does not add states if they have been marked */
void enqueue(StateQueue &f, Problem &p, State s)
{
  if(p.getFrontier(s))
    return;
  p.setFrontier(s);
  f.enqueue(s);
}

/** conducts a BFS
 * @param problem problem object containing maze object, present state, and a list of goal states
 * @return solution state 
 * @note state is stored internally (problem object) */
State breadthFirstSearch(Problem problem, vector<State> &exvec)
{
  // check initial state
  if(problem.goal())
    return problem.initial();

  // intialize frontier queue and explored vector
  StateQueue frontier;        // dynamic array should use a large resize factor (for speed)
  vector<State> explored;
  size_t frontier_size = 1;

  // add initial value to frontier
  enqueue(frontier, problem, problem.initial());

  // loop
  size_t cycle = 1000, count = 0;
  float sec, prev = 0.0;
  while(!frontier.isEmpty())
  {
    if(count % cycle == 0){
      sec = (float)clock()/CLOCKS_PER_SEC;
      cout
        << "States Explored: " << count
        << "\ttime (sec): " << sec
        << "\trate (states/sec): " << (float)cycle / (sec-prev)
        << "\tfrontier size: " << frontier_size << endl;
      prev = sec;
    }count++;

    problem.setState(frontier.peekFront());
    frontier.dequeue();
    frontier_size--;
    if(problem.goal())
      return problem.getState(); exvec = explored;
    explored.push_back(problem.getState());
    problem.setExplored(problem.getState());
    for(State next : problem.actions()){
      if(!problem.getExplored(next)){
        enqueue(frontier, problem, next);
        frontier_size++;
      }
    }
  }

  // if frontier is empty, all states are explored with no solution --> return failure
  exvec = explored;
  return Fail_State;
}

