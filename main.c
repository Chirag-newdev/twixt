#include "depn.h"
char arr[SIZE][SIZE];
int main()
{
    memset(arr,'.',sizeof(arr));
    bool x=0;
    int i=10;
    display();
    while(i--)
    {
        int t=-1;
        while(t==-1)
            t=pin(x?'X':'O');
        x=!x;
        link(t/SIZE,t%SIZE);
    }
    return 0;
}