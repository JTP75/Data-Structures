#ifndef _PROBLEM_HPP_
#define _PROBLEM_HPP_

#include "Maze.hpp"
#include "dynamic_array_list.hpp"
#include <iostream>
#include <vector>

class Problem
{
  private:
    State state;                      // current state
    Maze maze;                        // maze object
    std::vector<State> goalStates;    // list of goal states as (row,col) pairs

  public:
    Problem(Maze m);
    ~Problem();
    State initial() const;
    bool goal() const;
    std::vector<State> actions(State s) const;

};

#include "Problem.cpp"

#endif