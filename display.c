#include "var.h"
#define H "\033[1B\033[1D"
#include "display.h"
void display()
{
    #ifdef WIN32 
    system("cls");
    #else
    system("clear");
    #endif
    printf("   ");
    for(int i=0;i<SIZE;i++)printf("%d%s",i,i<10?"   ":"  ");
    arr[0][0]=arr[0][SIZE-1]=arr[SIZE-1][0]=arr[SIZE-1][SIZE-1]=' ';
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d%s",i,i<10?"  ":" ");
        print(arr[i]);
        printf("\n\n");
    }
    printf("\033[31m\0337\033[%d;%dH-------------------------------------------------------------------------------------\0338\033[0m",3,8);
    printf("\033[31m\0337\033[%d;%dH-------------------------------------------------------------------------------------\0338\033[0m",47,8);
    printf("\033[34m\0337\033[%d;%dH"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|""\0338\033[0m",3,7);
    printf("\033[34m\0337\033[%d;%dH"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|"H"|""\0338\033[0m",3,95);
    return;
}
