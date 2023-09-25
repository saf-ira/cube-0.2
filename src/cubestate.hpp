#include <iostream>
#include <random>
#include <chrono>

class cubestate {
    public:

    void start(int state[]);
    void callstate(int state[]);
    void R(int state[]);
    void Rprime(int state[]);
    void L(int state[]);
    void Lprime(int state[]);
    void U(int state[]);
    void Uprime(int state[]);
    void D(int state[]);
    void Dprime(int state[]);
    void B(int state[]);
    void Bprime(int state[]);
    void F(int state[]);
    void Fprime(int state[]);
    void getRandMove(int state[]);
    void scramble(int state[]);

};
