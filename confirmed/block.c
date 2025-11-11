#include "block.h"
void block(int x,int y,int dx,int dy)
{
    if(dx==1)
    {
        {
            state[x+1][y]=state[x+1][y+dy/2]=1;
        }
    }
    else if(dx==-1)
    {
        x--;
        state[x+1][y]=state[x+1][y+dy/2]=1;
    }
    else if(dx==2)
    {
        if(dy==1)state[x+dx/2][y]=state[x][y]=1;
    }
    else state[x+dx/2][y]=state[x][y]=1;
    return;
}