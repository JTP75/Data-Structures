#ifndef _MAZE_HPP_
#define _MAZE_HPP_

#include "lib/image.h"
#include <iostream>

struct MazeSquare {
    bool traversable;       // false if black
    bool isEdge;            // true if on edge
    bool isExit;            // true if both of above are true
    bool frontier = false;  // true if square was added to frontier
};

// state is current coordinates
struct State{
  int rpos;
  int cpos;
};

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
        MazeSquare getSquare(State s) const;
        unsigned getExitCount() const;
        State getInit() const noexcept {return init;};
        unsigned h() const {return rows;};
        unsigned w() const {return cols;};
        void setFrontier(State s);

    private:
    
        MazeSquare** maze;
        State init;
        unsigned rows, cols;

};

#include "Maze.cpp"

#endif