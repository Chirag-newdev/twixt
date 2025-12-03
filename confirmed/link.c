#include "link.h"
#define tw "\n\033[1B\033[1D"
#define kw "\033[1B\033[1D"
void link(int x,int y)
{
    char a[8][2]={{x+2,y+1},{x+1,y+2},{x+2,y-1},{x+1,y-2},{x-1,y-2},{x-2,y-1},{x-2,y+1},{x-1,y+2}};
    for(int i=0;i<8;i++)
    {
        char x1=a[i][0];
        char y1=a[i][1];
        int dx=x1-x,dy=y1-y;
        char z= dx*dy>0?'\\':'/';
        if((x1<0||x1>=SIZE) || (y1<0||y1>=SIZE))continue;
        if(arr[x][y]!=arr[x1][y1])continue;
        if(!check(x,y,dx,dy))continue;
        if(abs(dx)==1)
        {
            printf("\0337");
            printf("\033[%d;%dH", (x+x1)+2,1+(y+y1)*2);
            printf("%c-----%c",z,z);
            fflush(stdout);
            printf("\0338");
        }
        else
        {
            printf("\0337");
            printf("\033[%d;%dH", (x+x1),4+(y+y1)*2);
            // printf("%c"kw"|"kw"|"kw""kw"%c",z,z);
            printf(kw" %c"kw"|"kw"%c",z,z);
            fflush(stdout);
            printf("\0338");
        }
    }
    return;
}