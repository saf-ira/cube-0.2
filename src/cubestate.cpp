#include "cubestate.hpp"

//the cubes state is stored by creating a length 48 array where each integer in the array represents a location on a rubix cubestate, and the integers store the piece in that space
//the cube starts in the solved state, such that space 0 is occupied by piece 0, space 1 by piece 1, and so on
void cubestate::start(int state[])
{
    
    for(int i = 0; i < 48; i++)
    {
        state[i] = i;
    }
}

void cubestate::callstate(int state[])
{
    //iterates once for each space on the cube, printing the number of the piece
    for(int i = 0; i < 16; i+=5)
    {
        std::cout << state[i] << " " << state[i+1] << " " << state[i+2] << ", " << state[i+3] << " " << state[i+4] << ", ";

    }
    for(int i = 20; i < 27; i+=2)
    {
        std::cout << state[i] << " " << state[i+1] << ", ";
    }
    for(int i = 28; i < 48; i+=5)
    {
        std::cout << state[i] << " " << state[i+1] << " " << state[i+2] << ", " << state[i+3] << " " << state[i+4] << ", ";
    }
    std::cout << '\n';
}


void cubestate::R(int state[])
{
    //a move is commenced by taking the state of a single face and placing it in a temporary array
    int temp[]{ state[7], state[5], state[6], state[9], state[8], state[11], state[12], state[10], state[24], state[25], state[38], state[39], state[40], state[36], state[37], state[35], state[33], state[34], state[23], state[22] };
    
    //each piece is replaced by the one 5 spaces IN FRONT of it
    state[7] = temp[5];
    state[5] = temp[6];
    state[6] = temp[7];
    state[9] = temp[8];
    state[8] = temp[9];
    state[11] = temp[10];
    state[12] = temp[11];
    state[10] = temp[12];
    state[24] = temp[13];
    state[25] = temp[14];
    state[38] = temp[15];
    state[39] = temp[16];
    state[40] = temp[17];
    state[36] = temp[18];
    state[37] = temp[19];
    state[35] = temp[0];
    state[33] = temp[1];
    state[34] = temp[2];
    state[23] = temp[3];
    state[22] = temp[4];
    //on a cube this would represent the right face rotating clockwise
}

void cubestate::Rprime(int state[])
{
    //the state of a single side is stored again using a temporary array
    int temp[]{ state[7], state[5], state[6], state[9], state[8], state[11], state[12], state[10], state[24], state[25], state[38], state[39], state[40], state[36], state[37], state[35], state[33], state[34], state[23], state[22] };
   
    //each piece is replaced by the one 5 spaces BEHIND it
    state[7] = temp[15];
    state[5] = temp[16];
    state[6] = temp[17];
    state[9] = temp[18];
    state[8] = temp[19];
    state[11] = temp[0];
    state[12] = temp[1];
    state[10] = temp[2];
    state[24] = temp[3];
    state[25] = temp[4];
    state[38] = temp[5];
    state[39] = temp[6];
    state[40] = temp[7];
    state[36] = temp[8];
    state[37] = temp[9];
    state[35] = temp[10];
    state[33] = temp[11];
    state[34] = temp[12];
    state[23] = temp[13];
    state[22] = temp[14];
    //on a cube this would represent the right face rotating counterclockwise
}

void cubestate::L(int state[])
{
    int temp[]{ state[17], state[15], state[16], state[19], state[18], state[1], state[2], state[0], state[20], state[21], state[28], state[29], state[30], state[46], state[47], state[45], state[43], state[44], state[27], state[26] };
    state[17] = temp[5];
    state[15] = temp[6];
    state[16] = temp[7];
    state[19] = temp[8];
    state[18] = temp[9];
    state[1] = temp[10];
    state[2] = temp[11];
    state[0] = temp[12];
    state[20] = temp[13];
    state[21] = temp[14];
    state[28] = temp[15];
    state[29] = temp[16];
    state[30] = temp[17];
    state[46] = temp[18];
    state[47] = temp[19];
    state[45] = temp[0];
    state[43] = temp[1];
    state[44] = temp[2];
    state[27] = temp[3];
    state[26] = temp[4];
}

void cubestate::Lprime(int state[])
{
    int temp[]{ state[17], state[15], state[16], state[19], state[18], state[1], state[2], state[0], state[20], state[21], state[28], state[29], state[30], state[46], state[47], state[45], state[43], state[44], state[27], state[26] };
    state[17] = temp[15];
    state[15] = temp[16];
    state[16] = temp[17];
    state[19] = temp[18];
    state[18] = temp[19];
    state[1] = temp[0];
    state[2] = temp[1];
    state[0] = temp[2];
    state[20] = temp[3];
    state[21] = temp[4];
    state[28] = temp[5];
    state[29] = temp[6];
    state[30] = temp[7];
    state[46] = temp[8];
    state[47] = temp[9];
    state[45] = temp[10];
    state[43] = temp[11];
    state[44] = temp[12];
    state[27] = temp[13];
    state[26] = temp[14];
}

void cubestate::U(int state[])
{
    int temp[]{ state[29], state[30], state[28], state[32], state[31], state[34], state[35], state[33], state[37], state[36], state[39], state[40], state[38], state[42], state[41], state[44], state[45], state[43], state[47], state[46] };
    state[29] = temp[5];
    state[30] = temp[6];
    state[28] = temp[7];
    state[32] = temp[8];
    state[31] = temp[9];
    state[34] = temp[10];
    state[35] = temp[11];
    state[33] = temp[12];
    state[37] = temp[13];
    state[36] = temp[14];
    state[39] = temp[15];
    state[40] = temp[16];
    state[38] = temp[17];
    state[42] = temp[18];
    state[41] = temp[19];
    state[44] = temp[0];
    state[45] = temp[1];
    state[43] = temp[2];
    state[47] = temp[3];
    state[46] = temp[4];
}

void cubestate::Uprime(int state[])
{
    int temp[]{ state[29], state[30], state[28], state[32], state[31], state[34], state[35], state[33], state[37], state[36], state[39], state[40], state[38], state[42], state[41], state[44], state[45], state[43], state[47], state[46] };
    state[29] = temp[15];
    state[30] = temp[16];
    state[28] = temp[17];
    state[32] = temp[18];
    state[31] = temp[19];
    state[34] = temp[0];
    state[35] = temp[1];
    state[33] = temp[2];
    state[37] = temp[3];
    state[36] = temp[4];
    state[39] = temp[5];
    state[40] = temp[6];
    state[38] = temp[7];
    state[42] = temp[8];
    state[41] = temp[9];
    state[44] = temp[10];
    state[45] = temp[11];
    state[43] = temp[12];
    state[47] = temp[13];
    state[46] = temp[14];
}

void cubestate::D(int state[])
{
    int temp[]{ state[15], state[16], state[17], state[13], state[14], state[10], state[11], state[12], state[8], state[9], state[5], state[6], state[7], state[3], state[4], state[0], state[1], state[2], state[18], state[19] };
    state[15] = temp[5];
    state[16] = temp[6];
    state[17] = temp[7];
    state[13] = temp[8];
    state[14] = temp[9];
    state[10] = temp[10];
    state[11] = temp[11];
    state[12] = temp[12];
    state[8] = temp[13];
    state[9] = temp[14];
    state[5] = temp[15];
    state[6] = temp[16];
    state[7] = temp[17];
    state[3] = temp[18];
    state[4] = temp[19];
    state[0] = temp[0];
    state[1] = temp[1];
    state[2] = temp[2];
    state[18] = temp[3];
    state[19] = temp[4];
}

void cubestate::Dprime(int state[])
{
    int temp[]{ state[15], state[16], state[17], state[13], state[14], state[10], state[11], state[12], state[8], state[9], state[5], state[6], state[7], state[3], state[4], state[0], state[1], state[2], state[18], state[19] };
    state[15] = temp[15];
    state[16] = temp[16];
    state[17] = temp[17];
    state[13] = temp[18];
    state[14] = temp[19];
    state[10] = temp[0];
    state[11] = temp[1];
    state[12] = temp[2];
    state[8] = temp[3];
    state[9] = temp[4];
    state[5] = temp[5];
    state[6] = temp[6];
    state[7] = temp[7];
    state[3] = temp[8];
    state[4] = temp[9];
    state[0] = temp[10];
    state[1] = temp[11];
    state[2] = temp[12];
    state[18] = temp[13];
    state[19] = temp[14];
}

void cubestate::B(int state[])
{
    int temp[]{ state[43], state[44], state[45], state[41], state[42], state[40], state[38], state[39], state[25], state[24], state[12], state[10], state[11], state[14], state[13], state[16], state[17], state[15], state[26], state[27] };
    state[43] = temp[5];
    state[44] = temp[6];
    state[45] = temp[7];
    state[41] = temp[8];
    state[42] = temp[9];
    state[40] = temp[10];
    state[38] = temp[11];
    state[39] = temp[12];
    state[25] = temp[13];
    state[24] = temp[14];
    state[12] = temp[15];
    state[10] = temp[16];
    state[11] = temp[17];
    state[14] = temp[18];
    state[13] = temp[19];
    state[16] = temp[0];
    state[17] = temp[1];
    state[15] = temp[2];
    state[26] = temp[3];
    state[27] = temp[4];
}

void cubestate::Bprime(int state[])
{
    int temp[]{ state[43], state[44], state[45], state[41], state[42], state[40], state[38], state[39], state[25], state[24], state[12], state[10], state[11], state[14], state[13], state[16], state[17], state[15], state[26], state[27] };
    state[43] = temp[15];
    state[44] = temp[16];
    state[45] = temp[17];
    state[41] = temp[18];
    state[42] = temp[19];
    state[40] = temp[0];
    state[38] = temp[1];
    state[39] = temp[2];
    state[25] = temp[3];
    state[24] = temp[4];
    state[12] = temp[5];
    state[10] = temp[6];
    state[11] = temp[7];
    state[14] = temp[8];
    state[13] = temp[9];
    state[16] = temp[10];
    state[17] = temp[11];
    state[15] = temp[12];
    state[26] = temp[13];
    state[27] = temp[14];
}

void cubestate::F(int state[])
{
    int temp[]{ state[2], state[0], state[1], state[4], state[3], state[6], state[7], state[5], state[22], state[23], state[33], state[34], state[35], state[31], state[32], state[30], state[28], state[29], state[21], state[20] };
    state[2] = temp[5];
    state[0] = temp[6];
    state[1] = temp[7];
    state[4] = temp[8];
    state[3] = temp[9];
    state[6] = temp[10];
    state[7] = temp[11];
    state[5] = temp[12];
    state[22] = temp[13];
    state[23] = temp[14];
    state[33] = temp[15];
    state[34] = temp[16];
    state[35] = temp[17];
    state[31] = temp[18];
    state[32] = temp[19];
    state[30] = temp[0];
    state[28] = temp[1];
    state[29] = temp[2];
    state[21] = temp[3];
    state[20] = temp[4];
}

void cubestate::Fprime(int state[])
{
    int temp[]{ state[2], state[0], state[1], state[4], state[3], state[6], state[7], state[5], state[22], state[23], state[33], state[34], state[35], state[31], state[32], state[30], state[28], state[29], state[21], state[20] };
    state[2] = temp[15];
    state[0] = temp[16];
    state[1] = temp[17];
    state[4] = temp[18];
    state[3] = temp[19];
    state[6] = temp[0];
    state[7] = temp[1];
    state[5] = temp[2];
    state[22] = temp[3];
    state[23] = temp[4];
    state[33] = temp[5];
    state[34] = temp[6];
    state[35] = temp[7];
    state[31] = temp[8];
    state[32] = temp[9];
    state[30] = temp[10];
    state[28] = temp[11];
    state[29] = temp[12];
    state[21] = temp[13];
    state[20] = temp[14];
}

void cubestate::getRandMove(int state[])
{
    //seed the marsenne twister using system clock
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(
        std::chrono::steady_clock::now().time_since_epoch().count()
    ) };
    //create a reusable random number generator from 1 - 12
    std::uniform_int_distribution move{ 1, 12 };
    
    //use the random number generator to pull a random possible move, apply it to the cubestate state and print the move it made
    int randMove = move(mt);
    
    if(randMove == 1)
    {
        std::cout << "R, ";
        R(state);
    }else if(randMove == 2){
        std::cout << "R', ";
        Rprime(state);
    }else if(randMove == 3){
        std::cout << "L, ";
        L(state);
    }else if(randMove == 4){
        std::cout << "L', ";
        Lprime(state);
    }else if(randMove == 5){
        std::cout << "U, ";
        U(state);
    }else if(randMove == 6){
        std::cout << "U', ";
        Uprime(state);
    }else if(randMove == 7){
        std::cout << "D, ";
        D(state);
    }else if(randMove == 8){
        std::cout << "D', ";
        Dprime(state);
    }else if(randMove == 9){
        std::cout << "B, ";
        B(state);
    }else if(randMove == 10){
        std::cout << "B', ";
        Bprime(state);
    }else if(randMove == 11){
        std::cout << "F, ";
        F(state);
    }else if(randMove == 12){
        std::cout << "F', ";
        Fprime(state);
    }else{
    }
}

void cubestate::scramble(int state[])
{
    //calls the random move function 25 times to generate a random scramble
    for(int i = 0; i < 25; i++)
    {
        getRandMove(state);
    }
    std::cout << '\n';
}
