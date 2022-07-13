#ifndef _MAZE_HPP_
#define _MAZE_HPP_

#include "lib/image.h"
#include <iostream>

struct MazeSquare {
    bool traversable;     // false if black
    bool isEdge;          // true if on edge
    bool isExit;          // true if both of above are true
};

// state is current coordinates
struct State{
  int rpos;
  int cpos;
};

// note: maze objects are immutable (since they cant be changed after construction, copying is pointless)
class Maze {
    public:
        // ctor, dtor, and coopy
        Maze();
        Maze(Image<Pixel> im);
        Maze(const Maze &m);
        Maze &operator=(const Maze m);
        ~Maze();
        // accessors
        MazeSquare getSquare(unsigned i, unsigned j) const;
        unsigned getExitCount() const;
        State getInit() const {return init;};

    private:
    
        MazeSquare **maze;
        State init;
        unsigned rows, cols;

};

#include "Maze.cpp"

#endif