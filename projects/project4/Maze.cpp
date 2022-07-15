#include "Maze.hpp"

Maze::Maze()
{
    maze = nullptr;
    init.rpos = 0;
    init.cpos = 0;
    rows = 0;
    cols = 0;
}
Maze::Maze(Image<Pixel> im)
{
    rows = im.height();
    cols = im.width();
    maze = new MazeSquare*[rows];           // allocate ptr array for rows
    for(int i=0; i<rows; i++)
        maze[i] = new MazeSquare[cols];     // for each row ptr, allocate a col

    // yes, i have been writing WAY too much matlab

    int redcount = 0;
    for(int i=0; i < rows; i++){
        for(int j=0; j < cols; j++){

            maze[i][j].traversable = im(i,j) != BLACK;
            maze[i][j].isEdge = i==0 || i==rows-1 || j==0 || j==cols-1;
            maze[i][j].isExit = maze[i][j].isEdge && maze[i][j].traversable;

            if(im(i,j) == RED){
                redcount++;
                init.rpos = i;
                init.cpos = j;
            }
            else if(im(i,j) != RED && im(i,j) != WHITE && im(i,j) != BLACK){
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
}
Maze::Maze(const Maze &m)
{
    rows = m.rows;
    cols = m.cols;
    init = m.init;

    maze = new MazeSquare*[rows];
    for(int i=0; i<rows; i++)
        maze[i] = new MazeSquare[cols];

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            maze[i][j] = m.maze[i][j];
}
Maze &Maze::operator=(const Maze m)
{
    rows = m.rows;
    cols = m.cols;
    init = m.init;

    maze = new MazeSquare*[rows];
    for(int i=0; i<rows; i++)
        maze[i] = new MazeSquare[cols];

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            maze[i][j] = m.maze[i][j];

    return *this;
}
Maze::~Maze()
{
    delete [] maze;
}

MazeSquare Maze::getSquare(unsigned i, unsigned j) const
{
    return maze[i][j];
}
MazeSquare Maze::getSquare(State s) const
{
    int i = s.rpos;
    int j = s.cpos;
    return maze[i][j];
}
unsigned Maze::getExitCount() const
{
    unsigned count = 0;
    for(int i=0; i<rows; i++){
        if(maze[i][0].isExit)
            count++;
        if(maze[i][cols-1].isExit)
            count++;
    }
    for(int j=0; j<cols; j++){
        if(maze[0][j].isExit)
            count++;
        if(maze[rows-1][j].isExit)
            count++;
    }
    return count;
}
void Maze::setFrontier(State s)
{
    int i = s.rpos;
    int j = s.cpos;
    maze[i][j].frontier = true;
}
void Maze::setExplored(State s)
{
    int i = s.rpos;
    int j = s.cpos;
    maze[i][j].explored = true;
}


















