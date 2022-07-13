#include "Problem.hpp"

Problem::Problem(Maze m)
{
    maze = m;
    state = m.getInit();
    for(int i=0; i < maze.h(); i++)
        for(int j=0; j < maze.w(); j++)
            if(maze.getSquare(i,j).isExit){
                State s = {i,j};
                goalStates.push_back(s);
            }

}

Problem::~Problem()
{
}

State Problem::initial() const
{
    return maze.getInit();
}

bool Problem::goal() const
{
    for(State s : goalStates)
        if(state.rpos == s.rpos && state.cpos == s.cpos)
            return true;
    return false;
}

/** list of possible next states 
 * @param   s   present state
 * @return      list of possible next states (0-4);
 */
std::vector<State> Problem::actions(State s) const
{
    int i = s.rpos;
    int j = s.cpos;
    std::vector<State> possibleNextStates, allNextStates = {{i+1,j},{i-1,j},{i,j-1},{i,j+1}};   // up, down, left, right
    for(States)
}