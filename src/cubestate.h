#include <array>
#include <iostream>
#include <cstring>


#ifndef CUBESTATE_H_
#define CUBESTATE_H_

enum cubelet
{
    ERROR,
    N,
    
    bc,
    wc,
    oc,
    yc,
    rc,
    gc,

    b1,
    r1,
    w1,
    b2,
    w2,
    b3,
    w3,
    o3,
    b4,
    o4,
    b5,
    o5,
    y5,
    b6,
    y6,
    b7,
    y7,
    r7,
    b8,
    r8,
    r9,
    w9,
    w10,
    o10,
    o11,
    y11,
    y12,
    r12,
    r13,
    g13,
    w13,
    w14,
    g14,
    w15,
    g15,
    o15,
    o16,
    g16,
    o17,
    g17,
    y17,
    y18,
    g18,
    y19,
    g19,
    r19,
    r20,
    g20,
};

class cubestate {
    public:
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> R(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> state_init();
    int xpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate, cubelet targ_piece);
    int ypos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate, cubelet targ_piece);
    int zpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate, cubelet targ_piece);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> copy_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate);
    void call_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate);
};

#endif
