#include "print.h"
#include "var.h"
void print(char* s)
{
    int temp=strlen(s);
    for(int i=0;i<SIZE-1;i++)
    {
        printf("%c   ",s[i]);
    }
    printf("%c",s[SIZE-1]);
    return;
}
