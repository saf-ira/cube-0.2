#include "cubestate.hpp"
#include "solver.h"

cubestate cube;
solver solve;

int main()
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> state;
    state = cube.state_init();
    cube.call_state(state);

    std::cout << '\n' << '\n';

    state = cube.B(state);

    cube.call_state(state);
}
