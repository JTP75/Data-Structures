#include "Problem.hpp"

Problem::Problem(Maze m)
{
    maze = m;
    state = m.getInit();
}

Problem::~Problem()
{
    maze.~Maze();
}