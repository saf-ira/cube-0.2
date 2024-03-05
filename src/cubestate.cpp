#include "cubestate.h"



std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::state_init()
{

    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cs { {
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

return Cs;
}

int cubestate::xpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate, cubelet targ_piece)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if(Cstate[i][j][k] == targ_piece)
                {
                    return k;
                }
            }
        }
    }
    return ERROR;
}

int cubestate::ypos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate, cubelet targ_piece)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if(Cstate[i][j][k] == targ_piece)
                {
                    return j;
                }
            }
        }
    }
    return ERROR;
}

int cubestate::zpos(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate, cubelet targ_piece)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if(Cstate[i][j][k] == targ_piece)
                {
                    return i;
                }
            }
        }
    }
    return ERROR;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::R(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cs;

    Cs = copy_state(Cstate);

    Cs[3][1][0] = Cstate[3][0][3];
    Cs[3][0][3] = Cstate[3][3][4];
    Cs[3][3][4] = Cstate[3][4][1];

    Cs[3][0][1] = Cstate[3][1][4];
    Cs[3][1][4] = Cstate[3][4][3];
    Cs[3][4][3] = Cstate[3][1][0];

    Cs[4][1][1] = Cstate[4][1][3];
    Cs[4][1][3] = Cstate[4][3][3];
    Cs[4][3][3] = Cstate[4][3][1];
    return Cs;
}

std::array<std::array<std::array<cubelet, 5>, 5>, 5> cubestate::copy_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate)
{
    std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cs;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                Cs[i][j][k] = Cstate[i][j][k];
            }
        }
    }
    return Cs;
}


void cubestate::call_state(std::array<std::array<std::array<cubelet, 5>, 5>, 5> Cstate)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                switch(Cstate[i][j][k]) {
                    case N:
                    std::cout << "N  " << ", ";
                    break;
                    
                    case bc:
                    std::cout << "bc " << ", ";
                    break;
                    
                    case wc:
                    std::cout << "wc " << ", ";
                    break;

                    case oc:
                    std::cout << "oc " << ", ";
                    break;

                    case yc:
                    std::cout << "yc " << ", ";
                    break;

                    case rc:
                    std::cout << "rc " << ", ";
                    break;

                    case gc:
                    std::cout << "gc " << ", ";
                    break;

                    case b1:
                    std::cout << "b1 " << ", ";
                    break;

                    case r1:
                    std::cout << "r1 " << ", ";
                    break;

                    case w1:
                    std::cout << "w1 " << ", ";
                    break;

                    case b2:
                    std::cout << "b2 " << ", ";
                    break;

                    case w2:
                    std::cout << "w2 " << ", ";
                    break;

                    case b3:
                    std::cout << "b3 " << ", ";
                    break;

                    case w3:
                    std::cout << "w3 " << ", ";
                    break;

                    case o3:
                    std::cout << "o3 " << ", ";
                    break;

                    case b4:
                    std::cout << "b4 " << ", ";
                    break;

                    case o4:
                    std::cout << "o4 " << ", ";
                    break;

                    case b5:
                    std::cout << "b5 " << ", ";
                    break;

                    case o5:
                    std::cout << "o5 " << ", ";
                    break;

                    case y5:
                    std::cout << "y5 " << ", ";
                    break;

                    case b6:
                    std::cout << "b6 " << ", ";
                    break;

                    case y6:
                    std::cout << "y6 " << ", ";
                    break;

                    case b7:
                    std::cout << "b7 " << ", ";
                    break;

                    case y7:
                    std::cout << "y7 " << ", ";
                    break;

                    case r7:
                    std::cout << "r7 " << ", ";
                    break;

                    case b8:
                    std::cout << "b8 " << ", ";
                    break;

                    case r8:
                    std::cout << "r8 " << ", ";
                    break;

                    case r9:
                    std::cout << "r9 " << ", ";
                    break;

                    case w9:
                    std::cout << "w9 " << ", ";
                    break;

                    case w10:
                    std::cout << "w10" << ", ";
                    break;

                    case o10:
                    std::cout << "o10" << ", ";
                    break;

                    case o11:
                    std::cout << "o11" << ", ";
                    break;

                    case y11:
                    std::cout << "y11" << ", ";
                    break;

                    case y12:
                    std::cout << "y12" << ", ";
                    break;

                    case r12:
                    std::cout << "r12" << ", ";
                    break;

                    case r13:
                    std::cout << "r13" << ", ";
                    break;

                    case g13:
                    std::cout << "g13" << ", ";
                    break;

                    case w13:
                    std::cout << "w13" << ", ";
                    break;

                    case w14:
                    std::cout << "w14" << ", ";
                    break;

                    case g14:
                    std::cout << "g14" << ", ";
                    break;

                    case w15:
                    std::cout << "w15" << ", ";
                    break;

                    case g15:
                    std::cout << "g15" << ", ";
                    break;
                    
                    case o15:
                    std::cout << "o15" << ", ";
                    break;

                    case o16:
                    std::cout << "o16" << ", ";
                    break;

                    case g16:
                    std::cout << "g16" << ", ";
                    break;

                    case o17:
                    std::cout << "o17" << ", ";
                    break;

                    case g17:
                    std::cout << "g17" << ", ";
                    break;

                    case y17:
                    std::cout << "y17" << ", ";
                    break;
                    
                    case y18:
                    std::cout << "y18" << ", ";
                    break;

                    case g18:
                    std::cout << "g18" << ", ";
                    break;
                    
                    case y19:
                    std::cout << "y19" << ", ";
                    break;

                    case g19:
                    std::cout << "g19" << ", ";
                    break;

                    case r19:
                    std::cout << "r19" << ", ";
                    break;

                    case r20:
                    std::cout << "r20" << ", ";
                    break;

                    case g20:
                    std::cout << "g20" << ", ";
                    break;
                }
            }
            std::cout << '\n';
        }
        std ::cout << '\n';
    }
}
