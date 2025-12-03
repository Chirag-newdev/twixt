#include "check.h"
bool check(int x,int y,int dx,int dy)
{
    if(abs(dx)==1)
        {
            if(state[x+(dx>0)][y+(dy>0)] || state[x+(dx>0)][y+(dy>0)+dy/2])
            {
                return 0;
            }
        }
    else if(abs(dx)==2)
    {
        if(state[x+(dx>0)-(dx<0)][y+(dy>0)] || state[x+(dx>0)*dx][y+(dy>0)])
        {
            return 0;
        }
    }
    block(x, y, dx, dy);
    return true;
}
