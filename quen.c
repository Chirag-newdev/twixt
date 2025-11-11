#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 24
#define PLAYER_NONE 0
#define PLAYER_RED 1
#define PLAYER_BLUE 2

typedef struct {
    int x, y;
} Position;

typedef struct Bridge {
    Position start, end;
    struct Bridge* next;
} Bridge;

typedef struct {
    unsigned char board[BOARD_SIZE][BOARD_SIZE];
    Bridge* bridges[2]; // 0: Red, 1: Blue
    int current_player;
    bool game_over;
    Position last_move;
} GameState;

// Direction vectors for knight moves (bridge connections)
const int knight_dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int knight_dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// DFS visited array (stack allocated for efficiency)
static bool visited[BOARD_SIZE][BOARD_SIZE];

static inline bool is_valid_pos(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

static inline bool is_corner(int x, int y) {
    return (x == 0 || x == BOARD_SIZE-1) && (y == 0 || y == BOARD_SIZE-1);
}

static inline int get_opponent(int player) {
    return player == PLAYER_RED ? PLAYER_BLUE : PLAYER_RED;
}

static void init_game(GameState* game) {
    memset(game->board, PLAYER_NONE, sizeof(game->board));
    game->bridges[0] = NULL;
    game->bridges[1] = NULL;
    game->current_player = PLAYER_RED;
    game->game_over = false;
    game->last_move.x = -1;
    game->last_move.y = -1;
}

static bool bridges_intersect(Position a1, Position a2, Position b1, Position b2) {
    // Check if bridges share endpoints
    if ((a1.x == b1.x && a1.y == b1.y) || (a1.x == b2.x && a1.y == b2.y) ||
        (a2.x == b1.x && a2.y == b1.y) || (a2.x == b2.x && a2.y == b2.y)) {
        return true;
    }
    return false;
}

static bool can_place_bridge(GameState* game, Position start, Position end) {
    // Check if positions are valid knight moves
    int dx = abs(start.x - end.x);
    int dy = abs(start.y - end.y);
    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
        return false;
    }
    
    // Check for intersection with opponent bridges
    int opponent_idx = get_opponent(game->current_player) - 1;
    Bridge* bridge = game->bridges[opponent_idx];
    while (bridge) {
        if (bridges_intersect(start, end, bridge->start, bridge->end)) {
            return false;
        }
        bridge = bridge->next;
    }
    return true;
}

static void add_bridge(GameState* game, Position start, Position end) {
    Bridge* new_bridge = malloc(sizeof(Bridge));
    new_bridge->start = start;
    new_bridge->end = end;
    int player_idx = game->current_player - 1;
    new_bridge->next = game->bridges[player_idx];
    game->bridges[player_idx] = new_bridge;
}

static void free_bridges(Bridge* head) {
    while (head) {
        Bridge* temp = head;
        head = head->next;
        free(temp);
    }
}

static void cleanup_game(GameState* game) {
    free_bridges(game->bridges[0]);
    free_bridges(game->bridges[1]);
}

static bool dfs_check_win(GameState* game, int x, int y, bool horizontal) {
    if (!is_valid_pos(x, y) || visited[x][y] || game->board[y][x] != game->current_player) {
        return false;
    }
    
    visited[x][y] = true;
    
    // Check win condition
    if (horizontal) {
        if (x == BOARD_SIZE - 1) return true;
    } else {
        if (y == BOARD_SIZE - 1) return true;
    }
    
    // Check direct neighbors (for peg adjacency)
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (is_valid_pos(nx, ny) && !visited[nx][ny] && 
                game->board[ny][nx] == game->current_player) {
                if (dfs_check_win(game, nx, ny, horizontal)) {
                    return true;
                }
            }
        }
    }
    
    // Check bridge connections
    Bridge* bridge = game->bridges[game->current_player - 1];
    while (bridge) {
        if (bridge->start.x == x && bridge->start.y == y) {
            if (!visited[bridge->end.x][bridge->end.y]) {
                if (dfs_check_win(game, bridge->end.x, bridge->end.y, horizontal)) {
                    return true;
                }
            }
        }
        if (bridge->end.x == x && bridge->end.y == y) {
            if (!visited[bridge->start.x][bridge->start.y]) {
                if (dfs_check_win(game, bridge->start.x, bridge->start.y, horizontal)) {
                    return true;
                }
            }
        }
        bridge = bridge->next;
    }
    
    return false;
}

static bool check_win_condition(GameState* game) {
    memset(visited, 0, sizeof(visited));
    
    if (game->current_player == PLAYER_RED) {
        // Red connects top to bottom (horizontal win)
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (game->board[0][x] == PLAYER_RED && !visited[x][0]) {
                if (dfs_check_win(game, x, 0, true)) {
                    return true;
                }
            }
        }
    } else {
        // Blue connects left to right (vertical win)
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (game->board[y][0] == PLAYER_BLUE && !visited[0][y]) {
                if (dfs_check_win(game, 0, y, false)) {
                    return true;
                }
            }
        }
    }
    return false;
}

static void print_board(GameState* game) {
    printf("\n  ");
    for (int x = 0; x < BOARD_SIZE; x++) {
        printf("%2d", x % 10);
    }
    printf("\n");
    
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("%2d", y);
        for (int x = 0; x < BOARD_SIZE; x++) {
            char c = '.';
            if (game->board[y][x] == PLAYER_RED) c = 'R';
            else if (game->board[y][x] == PLAYER_BLUE) c = 'B';
            else if (is_corner(x, y)) c = '#';
            printf(" %c", c);
        }
        printf("\n");
    }
    printf("\nPlayer %s's turn\n", game->current_player == PLAYER_RED ? "RED" : "BLUE");
}

static bool make_move(GameState* game, int x, int y) {
    if (!is_valid_pos(x, y) || is_corner(x, y) || game->board[y][x] != PLAYER_NONE) {
        return false;
    }
    
    game->board[y][x] = game->current_player;
    game->last_move.x = x;
    game->last_move.y = y;
    
    // Check for possible bridges
    Position current_pos = {x, y};
    for (int i = 0; i < 8; i++) {
        int nx = x + knight_dx[i];
        int ny = y + knight_dy[i];
        
        if (is_valid_pos(nx, ny) && game->board[ny][nx] == game->current_player) {
            Position neighbor = {nx, ny};
            if (can_place_bridge(game, current_pos, neighbor)) {
                add_bridge(game, current_pos, neighbor);
            }
        }
    }
    
    if (check_win_condition(game)) {
        game->game_over = true;
        print_board(game);
        printf("Player %s wins!\n", game->current_player == PLAYER_RED ? "RED" : "BLUE");
        return true;
    }
    
    game->current_player = get_opponent(game->current_player);
    return true;
}

int main() {
    GameState game;
    init_game(&game);
    
    printf("Twixt Game - RED (connects top-bottom), BLUE (connects left-right)\n");
    printf("Enter moves as 'x y' coordinates (0-%d)\n", BOARD_SIZE-1);
    printf("Type 'q' to quit\n");
    
    while (!game.game_over) {
        print_board(&game);
        printf("Move (x y): ");
        
        char input[100];
        if (!fgets(input, sizeof(input), stdin)) break;
        
        if (input[0] == 'q' || input[0] == 'Q') {
            printf("Game quit.\n");
            break;
        }
        
        int x, y;
        if (sscanf(input, "%d %d", &x, &y) == 2) {
            if (!make_move(&game, x, y)) {
                printf("Invalid move! Try again.\n");
            }
        } else {
            printf("Invalid input! Enter coordinates as 'x y'.\n");
        }
    }
    
    cleanup_game(&game);
    return 0;
}
