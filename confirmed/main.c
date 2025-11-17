#include "depn.h"
char arr[SIZE][SIZE]={0};
bool state[SIZE+1][SIZE+1]={false};
int main()
{
    memset(arr,'.',sizeof(arr));
    memset(state,'0',sizeof(state));
    bool x=0;
    int i=40;
    initialize();
    display();
    while(i--)
    {
        int t=0;
        while(t<=0)
        {
            t=pin(x?'X':'O',t);
            if(t==-10)return 0;
        }
        x=!x;
        link(t/SIZE,t%SIZE);
    }
    return 0;
}