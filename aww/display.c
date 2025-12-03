#include "display.h"
#include <stdio.h>
#include <stdlib.h>

// ANSI Colors
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

void clear_screen() {
    system("cls");
}

void display_board(GameState *game) {
    clear_screen();
    
    // Header
    printf("\n  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    // Top Border (X's Goal)
    printf("   " GREEN);
    for (int i = 0; i < SIZE; i++) printf("---");
    printf(RESET "\n");

    for (int i = 0; i < SIZE; i++) {
        // Left Border (O's Goal)
        printf("%2d " RED "|" RESET, i);

        for (int j = 0; j < SIZE; j++) {
            char cell = '.';
            const char *color = RESET;

            if (game->board[i][j] == PLAYER_X) {
                cell = 'X';
                color = BLUE;
            } else if (game->board[i][j] == PLAYER_O) {
                cell = 'O';
                color = RED;
            }

            printf("%s %c " RESET, color, cell);
        }

        // Right Border (O's Goal)
        printf(RED "|" RESET "\n");
        
        // Draw Links (Simplified visual representation)
        // This is tricky in pure text. We might just draw the grid for now.
        // Drawing diagonal links in ASCII between rows is complex.
        // For "basic logic", a clean grid is often sufficient, but let's try to add some spacing.
        printf("\n"); 
    }

    // Bottom Border (X's Goal)
    printf("   " MAGENTA);
    for (int i = 0; i < SIZE; i++) printf("---");
    printf(RESET "\n");
}
