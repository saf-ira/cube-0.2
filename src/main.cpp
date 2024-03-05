#include "cubestate.h"
#include "solver.h"

cubestate cube;
solver solve;

int main()
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> state;
    state = cube.state_init();
    cube.call_state(state);

    int xpos = cube.xpos(state, b7);
    int ypos = cube.ypos(state, b7);
    int zpos = cube.zpos(state, b7);

    std::cout << xpos << ", " << ypos << ", " << zpos << ", ";
}
