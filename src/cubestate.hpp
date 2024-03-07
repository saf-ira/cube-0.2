#include <array>
#include <iostream>
#include <cstring>


#ifndef CUBESTATE_HPP_
#define CUBESTATE_HPP_

enum axis
{
    X,
    Y,
    Z,
};

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
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Rp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> R(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> L(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Lp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Up(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> U(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> D(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Dp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> F(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
     std::array<std::array<std::array<cubelet, 5>, 5>, 5> Fp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> B(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Bp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);

    std::array<std::array<std::array<cubelet, 5>, 5>, 5> state_init();
    int xpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, cubelet targ_piece);
    int ypos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, cubelet targ_piece);
    int zpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, cubelet targ_piece);

    std::array<std::array<std::array<cubelet, 5>, 5>, 5> rotate_slice(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, axis axis, int slice, int direction);
    void call_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);

    std::array<std::array<std::array<cubelet, 5>, 5>, 5> scramble_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state);
    
};

#endif
