#include "block.h"
void block(int x,int y,int dx,int dy)
{
    if(abs(dx)==1)state[x+(dx>0)][y+(dy>0)]=state[x+(dx>0)][y+(dy>0)+dy/2]=1;
    else if(abs(dx)==2)state[x+(dx>0)-(dx<0)][y+(dy>0)]=state[x+(dx>0)*dx][y+(dy>0)]=1;
    return;
}