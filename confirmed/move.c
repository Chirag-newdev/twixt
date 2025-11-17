#include "move.h"
#include "var.h"
int pin(char z,int flag)
{
    int x,y;
    printf("Player :%c, please enter row and comumn of your move in format:\"row column\"\n\033[2K",z);
    if(scanf(" %d %d",&x,&y)!=2)return -10;
    if((x<0||x>=SIZE) || (y<0||y>=SIZE))
    {
        printf("\0337");
        printf("\0338");
        printf("\033[3A");
        printf("out of bounds\n");
        return -2;
    }
    if((z=='O')&& (y==0||y==SIZE-1))
    {
        printf("\0337");
        printf("\0338");
        printf("\033[3A");
        printf("invalid move\n");
        return -2;
    }
    if((z=='X')&& (x==0||x==SIZE-1))
    {
        printf("\0337");
        printf("\0338");
        printf("\033[3A");
        printf("invalid move\n");
        return -2;
    }
    if(arr[x][y]=='.')
    {
        arr[x][y]=z;
        printf("\0337");
        printf("\033[r\033[H");
        printf("\033[%d;%dH", 2*x+2,4+y*4);
        if(z=='o')printf("%s","\033[31mO\033[0m");
        else printf("%s","\033[34mX\033[0m");
        fflush(stdout);
        printf("\0338");
        if(flag==-2)printf("\033[3A\n");
        return (x)*SIZE  +  (y);
    }
    else
    {
        printf("\033[2A");
        return -1;
    }
}
