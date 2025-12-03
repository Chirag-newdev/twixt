#include "checkwin.h"
int update(int x,int y)
{
    if(x<0||x>=SIZE||y<0||y>=SIZE)return 0;
    char a[8][2]={{x-2,y+1},{x-1,y+2},{x+1,y+2},{x+2,y+1},{x+2,y-1},{x+1,y-2},{x-1,y-2},{x-2,y-1}};
    if(wonq[x][y]!=0);
    else if(x==0)wonq[x][y]=-1;
    else if (y==0)wonq[x][y]=1;
    else if(arr[x][y]=='X')
    {
        for(int i=0;i<8;i++)
        {
            if(wonq[a[i][0]][a[i][1]]==-1)
            {
                wonq[x][y]=-1;
            }
        }
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            if(wonq[a[i][0]][a[i][1]]==1)
            {
                wonq[x][y]=1;
            }
        }
    }

    if(wonq[x][y]!=0)
    {
        for(int i=0;i<8;i++)
        {
            update(a[i][0],a[i][1]);
        }
    }
    return 0;
}
int checkwin()
{
    for(int i=0;i<SIZE;i++)
    {
        if(wonq[23][i]==-1)return -1;
        if(wonq[i][23]==1)return 1;
    }
    return 0;
}