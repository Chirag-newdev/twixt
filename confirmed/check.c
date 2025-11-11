#include "check.h"
bool check(int x,int y,int dx,int dy)
{
    if (dx == 1)
    {
        if (state[x+1][y] || state[x+1][y+dy/2]) return false;
    }
    else if (dx == -1)
    {
        if (state[x][y] || state[x][y+dy/2]) return false;
    }
    else if (dx == 2)
    {
        if (state[x+1][y] || state[x+1][y+dy/2]) return false;
    }
    else if (dx == -2)
    {
        if (state[x-1][y] || state[x-1][y+dy/2]) return false;
    }
    block(x, y, dx, dy);
    return true;
}
