#include "link.h"
#include "var.h"
#define tw "\n\033[1B\033[1D"

void link(int x,int y)
{
    char(*ptr)[] = arr;
    char flag=0;
    char a[8][2]={{x+2,y+1},{x+1,y+2},{x-2,y+1},{x-1,y-2},{x+2,y-2},{x+1,y-2},{x-2,y+1},{x-1,y+2}};
    for(int i=0;i<8;i++)
    {
        char x1=a[i][0];
        char y1=a[i][1];
        char z= (x1-x)*(y1-y)>0?'\\':'/';
        if(arr[x][y]==arr[x1][y1] && fabs(x-x1)==2)
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
            printf("\033[%d;%dH", (x+x1)+2,1+(y+y1)*2);
            printf("%c"tw"-"tw"-"tw"-"tw"-"tw"-"tw"%c",z,z);
            fflush(stdout);
            printf("\0338");

        }
    }
    return;
}