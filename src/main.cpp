#include "cubestate.hpp"
#include "solver.hpp"
cubestate cube;
solver solve;

int main()
{
    
    int state[48];
    cube.start(state);

    cube.scramble(state);

    cube.callstate(state);

    int pos;
    pos = solve.getPos(state, 3);

    std::cout << '\n' << pos;
    pos = solve.getPos(state, 4);

    std::cout << ", " << pos;


}
