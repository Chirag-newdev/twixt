#include "game.h"
#include <stdlib.h>
#include <math.h>

// Knight's move offsets
// 0: (-2, +1), 1: (-1, +2), 2: (+1, +2), 3: (+2, +1)
// 4: (+2, -1), 5: (+1, -2), 6: (-1, -2), 7: (-2, -1)
const int DX[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int DY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// --- Group Tracking (Array-based Union-Find) ---

// Find the representative of the group (iterative)
int find_group(int *parent, int i) {
    while (i != parent[i]) {
        parent[i] = parent[parent[i]]; // Path compression (optional but good)
        i = parent[i];
    }
    return i;
}

// Connect two groups
void union_groups(int *parent, int i, int j) {
    int root_i = find_group(parent, i);
    int root_j = find_group(parent, j);
    if (root_i != root_j) {
        parent[root_i] = root_j; // Simple union
    }
}

// --- Game Logic ---

void init_game(GameState *game) {
    // Clear board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = PLAYER_NONE;
            for (int k = 0; k < 8; k++) {
                game->links[i][j][k] = false;
            }
        }
    }

    // Initialize groups: everyone is their own parent
    for (int i = 0; i < MAX_NODES; i++) {
        game->parent[i] = i;
    }

    game->current_player = PLAYER_O; // O goes first usually
    game->winner = PLAYER_NONE;
}

bool is_valid_pos(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// Check for link crossing (Simplified check based on Twixt rules)
// This is a basic implementation. For a robust one, we'd check intersection of line segments.
// For now, we'll assume valid links don't cross existing links if we check carefully.
// In Twixt, links can't cross. We need to check if the path (x,y) -> (nx,ny) crosses any existing link.
// The midpoint of a knight move is (x+dx/2, y+dy/2).
// Crossing happens if another link goes through the "cross" of the knight move.
bool check_crossing(GameState *game, int x, int y, int dir) {
    // This part can be complex. For "basic logic", we might skip complex crossing checks 
    // or implement a simple one. Let's implement a simple check for the most common crosses.
    // A knight move (2,1) crosses with another (2,1) or (1,2) in specific ways.
    
    // For this implementation, we will focus on connectivity first. 
    // Crossing checks are omitted for simplicity as requested ("basic logic"), 
    // but can be added if strict rule enforcement is needed.
    return false; 
}

bool make_move(GameState *game, int x, int y) {
    // 1. Validation
    if (!is_valid_pos(x, y)) return false;
    if (game->board[x][y] != PLAYER_NONE) return false;

    // Edge constraints
    if (game->current_player == PLAYER_X) {
        if (x == 0 || x == SIZE - 1) return false; // X cannot play on top/bottom rows
    } else {
        if (y == 0 || y == SIZE - 1) return false; // O cannot play on left/right cols
    }

    // 2. Place Piece
    game->board[x][y] = game->current_player;
    int current_id = x * SIZE + y;

    // 3. Connect to Virtual Groups (Edges)
    if (game->current_player == PLAYER_X) {
        if (x == 1) union_groups(game->parent, current_id, V_TOP);
        if (x == SIZE - 2) union_groups(game->parent, current_id, V_BOTTOM);
    } else {
        if (y == 1) union_groups(game->parent, current_id, V_LEFT);
        if (y == SIZE - 2) union_groups(game->parent, current_id, V_RIGHT);
    }

    // 4. Connect to Neighbors (Links)
    for (int i = 0; i < 8; i++) {
        int nx = x + DX[i];
        int ny = y + DY[i];

        if (is_valid_pos(nx, ny) && game->board[nx][ny] == game->current_player) {
            // Check if link is valid (no crossing) - Skipping complex cross check for basic logic
            // In a full game, we'd check check_crossing(game, x, y, i) here.
            
            // Create Link
            game->links[x][y][i] = true;
            // The reverse link is implied or can be stored
            // game->links[nx][ny][(i + 4) % 8] = true; 

            // Union Groups
            int neighbor_id = nx * SIZE + ny;
            union_groups(game->parent, current_id, neighbor_id);
        }
    }

    // 5. Check Win
    game->winner = check_win(game);

    // 6. Switch Player
    game->current_player = (game->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    return true;
}

int check_win(GameState *game) {
    if (find_group(game->parent, V_TOP) == find_group(game->parent, V_BOTTOM)) {
        return PLAYER_X;
    }
    if (find_group(game->parent, V_LEFT) == find_group(game->parent, V_RIGHT)) {
        return PLAYER_O;
    }
    return PLAYER_NONE;
}
