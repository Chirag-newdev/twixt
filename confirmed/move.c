#include "move.h"
#include "var.h"

int pin(char z, int flag)
{
    int x, y;

    printf("%sPlayer %c, enter row and column :",flag==-2?"":"                " ,z);
    if (scanf("%d %d", &x, &y) != 2)
        return -10;
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) 
    {
        printf("\033[1A\033[2K\033[33m[out of bounds]\033[0m ");
        fflush(stdout);
        return -2;
    }

    if (z == 'O' && (y == 0 || y == SIZE - 1)) {
        printf("\033[1A\033[2K\033[33m[invalid move]\033[0m  ");
        fflush(stdout);
        return -2;
    }

    if (z == 'X' && (x == 0 || x == SIZE - 1)) {
        printf("\033[1A\033[2K\033[33m[invalid move]\033[0m  ");
        fflush(stdout);
        return -2;
    }

    if (arr[x][y] != '.') {
        printf("\033[1A\033[2K\033[33m[occupied]\033[0m      ");
        fflush(stdout);
        return -2;
    }
    arr[x][y] = z;
    printf("\033[s");
    printf("\033[r\033[H");
    printf("\033[%d;%dH", 2 * x + 2, 4 + y * 4);
    if (z == 'O')
        printf("\033[31mO\033[0m");
    else
        printf("\033[34mX\033[0m");
    fflush(stdout);
    printf("\033[u");
    printf("\033[%dA",flag==0?0:flag==-2?1:2);
    fflush(stdout);
    return x * SIZE + y;
}
