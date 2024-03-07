#include "cubestate.hpp"


// NOTE:
// NOTE:
// NOTE:

// the code only understand coord values in (z, y, x) this was very confusing at first and took a while to get used to it


    // also, any changes that are made to the state of the array are done with return statements, so to change an array you have to set it equal to the function call

// this takes the array and sets it up in the defualt starting cube position, then returns that position
std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::state_init()
{

    // all the values in here are from the cubelet enum in cubestate.hpp, the names are arbitrary. Ive simply given each unique cube piece its own number
    // (excluding the centers which have no number and are skipped) so each cubelet has a number identifier and a color identifier

    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp { {
        {{
            {N, N, N, N, N},
            {N, b1, b2, b3, N},
            {N, b8, bc, b4, N},
            {N, b7, b6, b5, N},
            {N, N, N, N, N},
        }},
        {{
            {N, w1, w2, w3, N},
            {r1, N, N, N, o3},
            {r8, N, N, N, o4},
            {r7, N, N, N, o5},
            {N, y7, y6, y5, N},
        }},
        {{
            {N, w9, wc, w10, N},
            {r9, N, N, N, o10},
            {rc, N, N, N,oc},
            {r12, N, N, N, o11},
            {N, y12, yc, y11, N},
        }},
        {{
            {N, w13, w14, w15, N},
            {r13, N, N, N, o15},
            {r20, N, N, N, o16},
            {r19, N, N, N, o17},
            {N, y19, y18, y17, N},
        }},
        {{
            {N, N, N, N, N},
            {N, g13, g14, g15, N},
            {N, g20, gc, g16, N},
            {N, g19, g18, g17, N},
            {N, N, N, N, N},
        }}

    } };

return temp;
}

// this iterates through every position in the array looking for a specific cubelet, when it finds that cubelet it returns the x coord as an int
int cubestate::xpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, cubelet targ_piece)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if(state[i][j][k] == targ_piece)
                {
                    return k;
                }
            }
        }
    }
    return ERROR;
}

// this is identical except it returns the y coord
int cubestate::ypos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, cubelet targ_piece)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if(state[i][j][k] == targ_piece)
                {
                    return j;
                }
            }
        }
    }
    return ERROR;
}

// exact same but for z coord, I did it this way so I can isolate one of the three coordinates, for any cubelet. 
// this should open up the door to create a function that will get the distance between a piece and a location
int cubestate::zpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, cubelet targ_piece)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if(state[i][j][k] == targ_piece)
                {
                    return i;
                }
            }
        }
    }
    return ERROR;
}

// function a friend made for me, I have yet to get it functioning so it is currently unused

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::rotate_slice(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state, axis axis, int slice, int direction) 
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp; // temp thing like before

    temp = state;
    int x, y, z; // coordinates for doing the stuff

    for (int i = 0; i < 3; i++) { // for each cublet in the slice of one of the axes
        for (int j = 0; j < 3; j++) { // for each cublet in the slice of the other axis
            switch (axis) { // which axis are we rotating?
                case X:
                    x = slice; // we doing x, then it stays the same
                    y = direction == 1 ? j : 2 - j; // cursed but it works by flipping the y coord if direction is -1
                    z = direction == 1 ? 2 - i : i; // this is different from the y coord because the z coord is flipped if direction is 1
                    temp[i][j][x] = state[z][y][x];
                    break;
                case Y:
                    x = direction == 1 ? 2 - j : j; // same thing as before but with x and y flipped
                    y = slice;
                    z = direction == 1 ? i : 2 - i; // same thing as before but with x and y flipped
                    temp[i][y][j] = state[z][y][x];
                    break;
                case Z:
                    x = direction == 1 ? i : 2 - i; // you get the idea
                    y = direction == 1 ? j : 2 - j;
                    z = slice;
                    temp[z][i][j] = state[z][y][x];
                    break;
            }
        }
    }

    return temp;
    /*
    for (int i = 0; i < 3; i++) { // for each cublet in the slice
        for (int j = 0; j < 3; j++) { // for each cublet in the slice
            switch (axis) {
                case 'x':
                    state[i][j][slice] = temp[i][j][slice]; // copy the cublet from the temp thing to the state
                    break;
                case 'y':
                    state[i][slice][j] = temp[i][slice][j]; // etc
                    break;
                case 'z':
                    state[i][j][slice] = temp[z][i][j];
                    break;
            }
        }
    }
    */
}

// this function manually represents the move by creating a temp array and swapping around specific values from the temp and main() array
std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::Rp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;

    temp = state;

// these are corner cubelets, each cube piece has 3 cubelets
    // these are corner cubelets that are all on the same x coord
    temp[0][1][3] = state[3][0][3];
    temp[3][0][3] = state[4][3][3];
    temp[4][3][3] = state[1][4][3];
    temp[1][4][3] = state[0][1][3];

    temp[1][0][3] = state[4][1][3];
    temp[4][1][3] = state[3][4][3];
    temp[3][4][3] = state[0][3][3];
    temp[0][3][3] = state[1][0][3];

    //these are corner cublets that are all on the same x coord as well, but a different x cooord as the previous two sets
    temp[1][1][4] = state[3][1][4];
    temp[3][1][4] = state[3][3][4];
    temp[3][3][4] = state[1][3][4];
    temp[1][3][4] = state[1][1][4];

// these are edge cubelets, each cube piece has 2 cubelets
    //same x coord
    temp[0][2][3] = state[2][0][3];
    temp[2][0][3] = state[4][2][3];
    temp[4][2][3] = state[2][4][3];
    temp[2][4][3] = state[0][2][3];

    //same x coord but different as last set
    temp[1][2][4] = state[2][1][4];
    temp[2][1][4] = state[3][2][4];
    temp[3][2][4] = state[2][3][4];
    temp[2][3][4] = state[1][2][4];
    
    return temp;
}

//this function mimics the R move by calling the Rprime move 3 times (which works on a real cube), its slightly slower in execution time from making a whole new function but its gonna take a lot less time to code and debug

//this function is a return statement so in order to call it correctly you set state in main() equal to R(state)

        //as a side note you can mimic the Rprime move by calling this R function 3 times, so by calling the Rprime move 9 times, you have mimiced the Rprime move
std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::R(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    
    temp = Rp(temp);
    temp = Rp(temp);
    temp = Rp(temp);

    return temp;
}

//same story here as with Rp
std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::L(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp[0][1][1] = state[3][0][1];
    temp[3][0][1] = state[4][3][1];
    temp[4][3][1] = state[1][4][1];
    temp[1][4][1] = state[0][1][1];

    temp[1][0][1] = state[4][1][1];
    temp[4][1][1] = state[3][4][1];
    temp[3][4][1] = state[0][3][1];
    temp[0][3][1] = state[1][0][1];

    temp[1][1][0] = state[3][1][0];
    temp[3][1][0] = state[3][3][0];
    temp[3][3][0] = state[1][3][0];
    temp[1][3][0] = state[1][1][0];

    temp[0][2][1] = state[2][0][1];
    temp[2][0][1] = state[4][2][1];
    temp[4][2][1] = state[2][4][1];
    temp[2][4][1] = state[0][2][1];

    temp[1][2][0] = state[2][1][0];
    temp[2][1][0] = state[3][2][0];
    temp[3][2][0] = state[2][3][0];
    temp[2][3][0] = state[1][2][0];

    return temp;
}
    //we mimic L prime the same way
std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::Lp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp = L(temp);
    temp = L(temp);
    temp = L(temp);

    return temp;
}

//same story here
std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::Up(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp[0][1][1] = state[3][1][0];
    temp[3][1][0] = state[4][1][3];
    temp[4][1][3] = state[1][1][4];
    temp[1][1][4] = state[0][1][1];

    temp[1][1][0] = state[4][1][1];
    temp[4][1][1] = state[3][1][4];
    temp[3][1][4] = state[0][1][3];
    temp[0][1][3] = state[1][1][0];

    temp[1][0][1] = state[3][0][1];
    temp[3][0][1] = state[3][0][3];
    temp[3][0][3] = state[1][0][3];
    temp[1][0][3] = state[1][0][1];

    temp[0][1][2] = state[2][1][0];
    temp[2][1][0] = state[4][1][2];
    temp[4][1][2] = state[2][1][4];
    temp[2][1][4] = state[0][1][2];

    temp[1][0][2] = state[2][0][1];
    temp[2][0][1] = state[3][0][2];
    temp[3][0][2] = state[2][0][3];
    temp[2][0][3] = state[1][0][2];

    return temp;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::U(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp = Up(temp);
    temp = Up(temp);
    temp = Up(temp);

    return temp;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::D(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp[0][3][1] = state[3][3][0];
    temp[3][3][0] = state[4][3][3];
    temp[4][3][3] = state[1][3][4];
    temp[1][3][4] = state[0][3][1];

    temp[1][3][0] = state[4][3][1];
    temp[4][3][1] = state[3][3][4];
    temp[3][3][4] = state[0][3][3];
    temp[0][3][3] = state[1][3][0];

    temp[1][4][1] = state[3][4][1];
    temp[3][4][1] = state[3][4][3];
    temp[3][4][3] = state[1][4][3];
    temp[1][4][3] = state[1][4][1];

    temp[0][3][2] = state[2][3][0];
    temp[2][3][0] = state[4][3][2];
    temp[4][3][2] = state[2][3][4];
    temp[2][3][4] = state[0][3][2];

    temp[1][4][2] = state[2][4][1];
    temp[2][4][1] = state[3][4][2];
    temp[3][4][2] = state[2][4][3];
    temp[2][4][3] = state[1][4][2];

    return temp;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::Dp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp = D(temp);
    temp = D(temp);
    temp = D(temp);

    return temp;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::F(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp[0][1][1] = state[0][3][1];
    temp[0][3][1] = state[0][3][3];
    temp[0][3][3] = state[0][1][3];
    temp[0][1][3] = state[0][1][1];

    temp[1][1][0] = state[1][4][1];
    temp[1][4][1] = state[1][3][4];
    temp[1][3][4] = state[1][0][3];
    temp[1][0][3] = state[1][1][0];

    temp[1][0][1] = state[1][3][0];
    temp[1][3][0] = state[1][4][3];
    temp[1][4][3] = state[1][1][4];
    temp[1][1][4] = state[1][0][1];

    temp[0][1][2] = state[0][2][1];
    temp[0][2][1] = state[0][3][2];
    temp[0][3][2] = state[0][2][3];
    temp[0][2][3] = state[0][1][2];

    temp[1][0][2] = state[1][2][0];
    temp[1][2][0] = state[1][4][2];
    temp[1][4][2] = state[1][2][4];
    temp[1][2][4] = state[1][0][2];

    return temp;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::Fp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp = F(temp);
    temp = F(temp);
    temp = F(temp);

    return temp;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::B(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp[3][0][3] = state[3][3][4];
    temp[3][3][4] = state[3][4][1];
    temp[3][4][1] = state[3][1][0];
    temp[3][1][0] = state[3][0][3];

    temp[3][1][4] = state[3][4][3];
    temp[3][4][3] = state[3][3][0];
    temp[3][3][0] = state[3][0][1];
    temp[3][0][1] = state[3][1][4];

    temp[4][1][3] = state[4][3][3];
    temp[4][3][3] = state[4][3][1];
    temp[4][3][1] = state[4][1][1];
    temp[4][1][1] = state[4][1][3];

    temp[3][0][2] = state[3][2][4];
    temp[3][2][4] = state[3][4][2];
    temp[3][4][2] = state[3][2][0];
    temp[3][2][0] = state[3][0][2];

    temp[4][1][2] = state[4][2][3];
    temp[4][2][3] = state[4][3][2];
    temp[4][3][2] = state[4][2][1];
    temp[4][2][1] = state[4][1][2];

   return temp;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::Bp(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;

    temp = B(temp);
    temp = B(temp);
    temp = B(temp);

    return temp;
}

//this just prints the state out to the console, it uses a big switch statement to convert the enum values into characters
//when looking in the console top left is (0, 0, 0) moving right increases x coord, 
void cubestate::call_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    // first for loop, this one increases the z coord by one every time
    for(int i = 0; i < 5; i++)
    {
        // second for loop, this one increases the y coord every time
        for(int j = 0; j < 5; j++)
        {
            // third for loop, this one increases the x coord every time
            for(int k = 0; k < 5; k++)
            {
                // all of this put together it increases the x coord by one 4 times, moves to another line and increases the y coord, then repeats
                // one set of x, y is done it moves down two times, increases the z coord by one and then repeats
                switch(state[i][j][k]) {
                    case N:
                    std::cout << "  " << "  ";
                    break;
                    
                    case bc:
                    std::cout << "bc " << "  ";
                    break;
                    
                    case wc:
                    std::cout << "wc " << "  ";
                    break;

                    case oc:
                    std::cout << "oc " << "  ";
                    break;

                    case yc:
                    std::cout << "yc " << "  ";
                    break;

                    case rc:
                    std::cout << "rc " << "  ";
                    break;

                    case gc:
                    std::cout << "gc " << "  ";
                    break;

                    case b1:
                    std::cout << "b1 " << "  ";
                    break;

                    case r1:
                    std::cout << "r1 " << "  ";
                    break;

                    case w1:
                    std::cout << "w1 " << "  ";
                    break;

                    case b2:
                    std::cout << "b2 " << "  ";
                    break;

                    case w2:
                    std::cout << "w2 " << "  ";
                    break;

                    case b3:
                    std::cout << "b3 " << "  ";
                    break;

                    case w3:
                    std::cout << "w3 " << "  ";
                    break;

                    case o3:
                    std::cout << "o3 " << "  ";
                    break;

                    case b4:
                    std::cout << "b4 " << "  ";
                    break;

                    case o4:
                    std::cout << "o4 " << "  ";
                    break;

                    case b5:
                    std::cout << "b5 " << "  ";
                    break;

                    case o5:
                    std::cout << "o5 " << "  ";
                    break;

                    case y5:
                    std::cout << "y5 " << "  ";
                    break;

                    case b6:
                    std::cout << "b6 " << "  ";
                    break;

                    case y6:
                    std::cout << "y6 " << "  ";
                    break;

                    case b7:
                    std::cout << "b7 " << "  ";
                    break;

                    case y7:
                    std::cout << "y7 " << "  ";
                    break;

                    case r7:
                    std::cout << "r7 " << "  ";
                    break;

                    case b8:
                    std::cout << "b8 " << "  ";
                    break;

                    case r8:
                    std::cout << "r8 " << "  ";
                    break;

                    case r9:
                    std::cout << "r9 " << "  ";
                    break;

                    case w9:
                    std::cout << "w9 " << "  ";
                    break;

                    case w10:
                    std::cout << "w10" << "  ";
                    break;

                    case o10:
                    std::cout << "o10" << "  ";
                    break;

                    case o11:
                    std::cout << "o11" << "  ";
                    break;

                    case y11:
                    std::cout << "y11" << "  ";
                    break;

                    case y12:
                    std::cout << "y12" << "  ";
                    break;

                    case r12:
                    std::cout << "r12" << "  ";
                    break;

                    case r13:
                    std::cout << "r13" << "  ";
                    break;

                    case g13:
                    std::cout << "g13" << "  ";
                    break;

                    case w13:
                    std::cout << "w13" << "  ";
                    break;

                    case w14:
                    std::cout << "w14" << "  ";
                    break;

                    case g14:
                    std::cout << "g14" << "  ";
                    break;

                    case w15:
                    std::cout << "w15" << "  ";
                    break;

                    case g15:
                    std::cout << "g15" << "  ";
                    break;
                    
                    case o15:
                    std::cout << "o15" << "  ";
                    break;

                    case o16:
                    std::cout << "o16" << "  ";
                    break;

                    case g16:
                    std::cout << "g16" << "  ";
                    break;

                    case o17:
                    std::cout << "o17" << "  ";
                    break;

                    case g17:
                    std::cout << "g17" << "  ";
                    break;

                    case y17:
                    std::cout << "y17" << "  ";
                    break;
                    
                    case y18:
                    std::cout << "y18" << "  ";
                    break;

                    case g18:
                    std::cout << "g18" << "  ";
                    break;
                    
                    case y19:
                    std::cout << "y19" << "  ";
                    break;

                    case g19:
                    std::cout << "g19" << "  ";
                    break;

                    case r19:
                    std::cout << "r19" << "  ";
                    break;

                    case r20:
                    std::cout << "r20" << "  ";
                    break;

                    case g20:
                    std::cout << "g20" << "  ";
                    break;
                }
            }
            std::cout << '\n';
        }
        std ::cout << '\n';
    }

    
}

cubelet getRandMove()
{

}


std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::scramble_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> state)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> temp;
    temp = state;
}
