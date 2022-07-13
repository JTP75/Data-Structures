#ifndef _PROBLEM_HPP_
#define _PROBLEM_HPP_

#include "Maze.hpp"
#include <iostream>

class Problem
{
  private:
    State state;
    Maze maze;

  public:
    Problem(Maze m);
    ~Problem();

};

#include "Problem.cpp"

#endif