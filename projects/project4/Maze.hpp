#ifndef _MAZE_HPP_
#define _MAZE_HPP_

#include "lib/image.h"
#include <vector>
#include <iostream>

struct MazeSquare {
  Pixel color;
  bool isEdge;
  bool isExit;
  unsigned traversalcount;
};
typedef std::vector<std::vector<MazeSquare>> Matrix;

class Maze {
    public:
        // public vals
        unsigned rpos, cpos;
        // ctor
        Maze(Image<Pixel> im);
        // nav
        bool up();
        bool down();
        bool left();
        bool right();
        // accessors
        MazeSquare getSquare(unsigned i, unsigned j) const;
        unsigned getExitCount() const;
        // reset
        void reset();

    private:
    
        Matrix maze;
        unsigned rInit, cInit;
        unsigned rows, cols;
        unsigned exitcount;

};

#include "Maze.cpp"

#endif