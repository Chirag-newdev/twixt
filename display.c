#include "var.h"
#include "display.h"
#include "print.h"
void display()
{
    system("cls");
    printf("   ");
    for(int i=0;i<SIZE;i++)printf("%d%s",i,i<10?"   ":"  ");
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d%s",i,i<10?"  ":" ");
        print(arr[i]);
        printf("\n\n");
    }
    return;
}
