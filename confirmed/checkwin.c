#include "checkwin.h"
int update(int x, int y)
{
    if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) return 0;
    char a[8][2] = {{x-2, y+1}, {x-1, y+2}, {x+1, y+2}, {x+2, y+1},{x+2, y-1}, {x+1, y-2}, {x-1, y-2}, {x-2, y-1}};
    if(wonq[x][y] == 0)
    {
        if(x == 1 && arr[x][y] == 'X') wonq[x][y] = -1;
        else if(y == 1 && arr[x][y] == 'O') wonq[x][y] = 1;
        else if(arr[x][y] == 'X')
        {
            for(int i = 0; i < 8; i++)
            {
                int nx = a[i][0];
                int ny = a[i][1];
                if(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE)
                {
                    if(ss[x][y][i] && wonq[nx][ny] == -1)
                    {
                        wonq[x][y] = -1;
                        break; 
                    }
                }
            }
        }
        else if(arr[x][y] == 'O')
        {
            for(int i = 0; i < 8; i++)
            {
                int nx = a[i][0];
                int ny = a[i][1];
                if(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE)
                {
                    if(ss[x][y][i] && wonq[nx][ny] == 1)
                    {
                        wonq[x][y] = 1;
                        break;
                    }
                }
            }
        }
    }
    if(wonq[x][y] != 0)
    {
        for(int i = 0; i < 8; i++)
        {
            if(ss[x][y][i])
            {
                int nx = a[i][0];
                int ny = a[i][1];
                if(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE)
                {
                    if(wonq[nx][ny] != wonq[x][y])
                    {
                        wonq[nx][ny] = wonq[x][y];
                        update(nx, ny);
                    }
                }
            }
        }
    }
    return 0;
}
int checkwin()
{
    for(int i = 1; i < SIZE-1; i++)
    {
        if(wonq[SIZE-1][i] == -1) return -1;
        if(wonq[i][SIZE-1] == 1) return 1;
    }
    return 0;
}