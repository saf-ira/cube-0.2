#include "cubestate.hpp"
#include "solver.hpp"

int solver::getPos(int state[], int piece)
{
    int pos{-1};
    
    for(int i = 0; i < 48; i++)
    {
        if(state[i] == piece)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void solver::cross(int state[])
{
 
}
