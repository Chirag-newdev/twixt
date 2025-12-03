#include "depn.h"
char arr[SIZE][SIZE]={0};
bool state[SIZE+5][SIZE+5]={false};
char connected[SIZE][SIZE]={0};
char links[SIZE][SIZE][8]={0};
int main()
{
    memset(arr,'.',sizeof(arr));
    memset(state,0,sizeof(state));
    bool x=0;
    int i=240;
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
        if(win())break;
    }
    return 0;
}