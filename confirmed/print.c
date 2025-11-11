#include "print.h"
void print(char* s)
{
    for(int i=0;i<SIZE-1;i++)
    {
        printf("%c   ",s[i]);
    }
    printf("%c",s[SIZE-1]);
    return;
}
