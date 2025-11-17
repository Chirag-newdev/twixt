#include <stdio.h>
int main()
{
    int *a,*b;
    *b=5;
    *a=*b+1;
    *b=10;
    printf("%d",*a);
    return 0;
}
