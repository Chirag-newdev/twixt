#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#define SIZE 24
#define MAX_NODES (SIZE * SIZE + 4)

// Virtual Nodes for Win Detection
#define V_TOP    (SIZE * SIZE)
#define V_BOTTOM (SIZE * SIZE + 1)
#define V_LEFT   (SIZE * SIZE + 2)
#define V_RIGHT  (SIZE * SIZE + 3)

// Player Types
#define PLAYER_NONE 0
#define PLAYER_X    1
#define PLAYER_O    2

// Game State
typedef struct {
    int board[SIZE][SIZE];      // Stores PLAYER_NONE, PLAYER_X, or PLAYER_O
    int parent[MAX_NODES];      // For group tracking (Union-Find)
    bool links[SIZE][SIZE][8];  // Tracks visual links: [x][y][dir]
    int current_player;
    int winner;                 // PLAYER_NONE, PLAYER_X, or PLAYER_O
} GameState;

// Core Functions
void init_game(GameState *game);
bool make_move(GameState *game, int x, int y);
int check_win(GameState *game);
bool is_valid_pos(int x, int y);

#endif
