#include "depn.h"
char arr[SIZE][SIZE]={0};
bool state[SIZE+5][SIZE+5]={false};
char ss[SIZE][SIZE][8]={0};
char wonq[SIZE][SIZE]={0};
int main()
{
    memset(arr,'.',sizeof(arr));
    memset(state,0,sizeof(state));
    bool x=0;
    int count=570;
    initialize();
    display();
    while(count--)
    {
        int t=0;
        while(t<=0)
        {
            t=pin(x?'X':'O',t);
            if(t==-10)return 0;
        }
        x=!x;
        link(t/SIZE,t%SIZE);
        update(t/SIZE,t%SIZE);
        int xyz=checkwin();
        if(xyz)
        {
            system("cls");
            printf("\n\033[32mPlayer %s wins\033[0m\n\n",xyz<0?"\033[34mX\033[0m":"\033[31mO\033[0m");
            return 0;
        }
    }
    return 0;
}