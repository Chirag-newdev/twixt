#include "game.h"
#include "display.h"
#include <stdio.h>

int main() {
    GameState game;
    init_game(&game);

    while (game.winner == PLAYER_NONE) {
        display_board(&game);

        printf("\nPlayer %s%c%s's turn.\n", 
            (game.current_player == PLAYER_X) ? BLUE : RED,
            (game.current_player == PLAYER_X) ? 'X' : 'O',
            RESET);
        printf("Enter move (row col): ");

        int r, c;
        if (scanf("%d %d", &r, &c) != 2) {
            // Handle invalid input
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        if (!make_move(&game, r, c)) {
            printf("Invalid move! Try again.\n");
            // Simple pause
            printf("Press Enter to continue...");
            while (getchar() != '\n');
            getchar();
        }
    }

    display_board(&game);
    printf("\n" YELLOW "GAME OVER! Player %c Wins!" RESET "\n", 
        (game.winner == PLAYER_X) ? 'X' : 'O');

    return 0;
}
