#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SIZE 24
#define tw "\n\033[1B\033[1D"

char arr[SIZE][SIZE];

void init(void) {
    memset(arr, '.', sizeof(arr));
}

void print(const char *s) {
    for (int i = 0; i < SIZE - 1; i++)
        printf("%c   ", s[i]);
    printf("%c", s[SIZE - 1]);
}

void display(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    printf("   ");
    for (int i = 0; i < SIZE; i++)
        printf("%d%s", i, i < 10 ? "   " : "  ");
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d%s", i, i < 10 ? "  " : " ");
        print(arr[i]);
        printf("\n\n");
    }
}

int render(char z) {
    int x, y;
    printf("Player %c, enter row and column (row col): \n", z);
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        printf("Out of bounds\n");
        return -1;
    }
    if (arr[x][y] == '.') {
        arr[x][y] = z;
        printf("\0337");
        printf("\033[%d;%dH", 2 * x + 2, 4 + y * 4);
        printf("%c", z);
        fflush(stdout);
        printf("\0338");
        printf("\033[2A");
        return x * SIZE + y;
    }
    return -1;
}
void link(int x, int y) {
    int moves[8][2] = {
        {x + 2, y + 1}, {x + 1, y + 2}, {x - 2, y + 1}, {x - 1, y - 2},
        {x + 2, y - 2}, {x + 1, y - 2}, {x - 2, y + 1}, {x - 1, y + 2}
    };

    for (int i = 0; i < 8; i++) {
        int x1 = moves[i][0];
        int y1 = moves[i][1];
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE)
            continue;

        char z = (x1 - x) * (y1 - y) > 0 ? '\\' : '/';

        if (arr[x][y] == arr[x1][y1]) {
            printf("\0337");
            printf("\033[%d;%dH", (x + x1) + 2, 1 + (y + y1) * 2);
            printf("%c-----%c", z, z);
            fflush(stdout);
            printf("\0338");
        }
    }
}

int main(void) {
    init();
    bool turn = false;
    int moves = 10;
    display();

    while (moves--) {
        int pos = render(turn ? 'X' : 'O');
        link(pos / SIZE, pos % SIZE);
        turn = !turn;
    }
    return 0;
}
