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
    // ctor/dtor
    Problem(Maze m);
    ~Problem();
    // listed fcns
    State initial() const noexcept;
    bool goal() const;
    std::vector<State> actions() const;
    // unlist fcns
    State getState() const noexcept;
    void setState(State s);
    void setFrontier(State s) {maze.setFrontier(s);};
    bool getFrontier(State s) const {return maze.getSquare(s).frontier;};
    void setExplored(State s) {maze.setExplored(s);};
    bool getExplored(State s) const {return maze.getSquare(s).explored;};

};

#include "Problem.cpp"

#endif