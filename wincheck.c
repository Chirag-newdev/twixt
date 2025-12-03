#include "wincheck.h"
bool win()
{
    for(int i=1;i<SIZE-1;i++)
    {
        if(connected[i][SIZE-1]==-1)printf("PLAYER: X HAS WON\n\n CONGRATS \n\nexiting...");
        else if(connected[SIZE-1][i]==1)printf("PLAYER: O HAS WON\n\n CONGRATS \n\nexiting...");
        else continue;
        return 1;
    }
    return 0;
}
int update(int x,int y)
{
    int a[8][2]={{x-2,y+1},{x-1,y+2},{x+1,y+2},{x+2,y+1},{x+2,y-1},{x+1,y-2},{x-1,y-2},{x-2,y-1}};
    if(connected[x][y]==0)
    {
        if(x==0)connected[x][y]=1;
        else if(y==0)connected[x][y]=-1;
        else for (int i = 0; i < 8; i++)
        {
            int x1=a[i][0];
            int y1=a[i][1];
            if((x1<0||x1>=SIZE) || (y1<0||y1>=SIZE))continue;
            else if(connected[x1][y1]!=0 && links[x][y][i]==1)
            {
                connected[x][y]=connected[x1][y1];
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if(connected[x][y]==0)continue;
        int x1=a[i][0];
        int y1=a[i][1];
        if((x1<0||x1>=SIZE) || (y1<0||y1>=SIZE))continue;
        if(connected[x1][y1]==0 && links[x][y][i]==1)update(x1,y1);
    }
    return 0;        
}