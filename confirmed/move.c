#include "move.h"
#include "var.h"

int pin(char z, int flag)
{
    int x, y;

    printf("Player %c, enter row and column:", z);
    if (scanf("%d %d", &x, &y) != 2)
        return -10;
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) 
    {
        printf("out of bounds\n");
        return -2;
    }

    if (z == 'O' && (y == 0 || y == SIZE - 1)) {
        printf("invalid move\n");
        return -2;
    }

    if (z == 'X' && (x == 0 || x == SIZE - 1)) {
        printf("invalid move\n");
        return -2;
    }

    if (arr[x][y] != '.') {
        printf("occupied\n");
        return -1;
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
    printf("\033[%dA",flag>0?2:flag==0?0:3);
    fflush(stdout);
    return x * SIZE + y;
}
