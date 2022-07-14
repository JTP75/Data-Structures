#include "Problem.hpp"

bool operator==(const State &LHS, const State &RHS);
bool operator!=(const State &LHS, const State &RHS);


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

/** gets initial state
 * @return initial state object */
State Problem::initial() const noexcept
{
    return maze.getInit();
}
/** determines if state is goal
 * @return true if state is goal, false if not */
bool Problem::goal() const
{
    for(State s : goalStates)
        if(state == s)
            return true;
    return false;
}
/** list of possible next states 
 * @return      list of possible next states (0-4) */
std::vector<State> Problem::actions() const
{
    int i = state.rpos;
    int j = state.cpos;
    std::vector<State> possibleNextStates, allNextStates = {{i+1,j},{i-1,j},{i,j-1},{i,j+1}};   // up, down, left, right
    for(State s : allNextStates)
        if(maze.getSquare(s).traversable)
            possibleNextStates.push_back(s);
    return possibleNextStates;
}

/** get current porblem state
 * @return current state of problem object */
State Problem::getState() const noexcept
{
    return state;
}
/** sets current state (MUST BE VALID NEXT STATE!!!) 
 * @param   st  new value for state
 * @throws  std::runtime_error if argument st is not a possible next state */
void Problem::setState(State st)
{
    // determine if state st is possible, throw exceptio if not
    if(!maze.getSquare(st).traversable){
        string desc =   "\nProblem::setState(State st): Requested State is not traversable!\n\tPresent state: (" + 
                        std::to_string(state.rpos) + "," + std::to_string(state.cpos) + ")" + 
                        "\tRequested state: (" + std::to_string(st.rpos) + "," + std::to_string(st.cpos) + ")\n";
        throw std::runtime_error(desc);
    }
    state = st;
    for(int i=0; i < maze.h(); i++)
        for(int j=0; j < maze.w(); j++)
            if(maze.getSquare(i,j).isExit){
                State s = {i,j};
                goalStates.push_back(s);
            }
}
/** resets state to initial problem state (stored in maze object) */
void Problem::reset() noexcept
{
    state = initial();
}


bool operator==(const State &LHS, const State &RHS)
{
    return LHS.rpos == RHS.rpos && LHS.cpos == RHS.cpos;
}
bool operator!=(const State &LHS, const State &RHS)
{
    return LHS.rpos != RHS.rpos || LHS.cpos != RHS.cpos;
}


