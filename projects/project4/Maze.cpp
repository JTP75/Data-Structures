#include "Maze.hpp"

Maze::Maze(Image<Pixel> im)
{
    rows = im.height();
    cols = im.width();

    int redcount = 0;
    for(int i=0; i < rows; i++){
        for(int j=0; j < cols; j++){

            maze[i][j].color = im(i,j);
            maze[i][j].isEdge = i==0 || i==rows-1 || j==0 || j==cols-1;
            maze[i][j].isExit = maze[i][j].isEdge && maze[i][j].color==WHITE;
            maze[i][j].traversalcount = 0;

            if(maze[i][j].color==RED){
                maze[i][j].traversalcount++;
                redcount++;
                rInit = i;
                cInit = j;
            }
            else if(maze[i][j].color!=RED && maze[i][j].color!=WHITE && maze[i][j].color!=BLACK){
                std::cerr << "Error! Maze contains pixels other than black, white, or red" << std::endl;
                std::string desc = "Maze::Maze() invalid image";
                throw std::runtime_error(desc);
            }

            if(redcount > 1){
                std::cerr << "Error! Maze contains more than one red pixel" << std::endl;
                std::string desc = "Maze::Maze() invalid image";
                throw std::runtime_error(desc);
            }

        }
    }
    if(redcount < 1){
        std::cerr << "Error! Maze contains no red pixels" << std::endl;
        std::string desc = "Maze::Maze() invalid image";
        throw std::runtime_error(desc);
    }
    rpos = rInit;
    cpos = cInit;
}

bool Maze::up() 
{
    if(maze[rpos+1][cpos].color == BLACK || rpos==0)
        return false;
    rpos--;
    return true;
}
bool Maze::down() 
{
    if(maze[rpos+1][cpos].color == BLACK || rpos==rows-1)
        return false;
    rpos++;
    return true;
}
bool Maze::left() 
{
    if(maze[rpos+1][cpos].color == BLACK || cpos==0)
        return false;
    cpos--;
    return true;
}
bool Maze::right() 
{
    if(maze[rpos+1][cpos].color == BLACK || cpos==cols-1)
        return false;
    rpos++;
    return true;
}

MazeSquare Maze::getSquare(unsigned i, unsigned j) const
{
    return maze[i][j];
}
unsigned Maze::getExitCount()























