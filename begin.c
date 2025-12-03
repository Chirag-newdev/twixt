#include "begin.h"

void initialize()
{
    printf(GREEN
        "  _________    _____  _____      _____      ____  ____    _________   \n"
        " |  _   _  |  |_   _||_   _|    |_   _|    |_  _||_  _|  |  _   _  |  \n"
        " |_/ | | \\_|    | | /\\ | |        | |        \\ \\  / /    |_/ | | \\_|  \n"
        "     | |        | |/  \\| |        | |         > `' <         | |      \n"
        "    _| |_       |   /\\   |       _| |_      _/ /'`\\ \\_      _| |_     \n"
        "   |_____|      |__/  \\__|      |_____|    |____||____|    |_____|    \n"
        RESET
        );

    printf("\n");
    printf("Player O: Connect " RED "TOP" RESET " to " BLUE "BOTTOM" RESET "\n");
    printf("Player X: Connect " GREEN "LEFT" RESET " to " MAGENTA "RIGHT" RESET "\n\n");

    printf("Rules:\n");
    printf(" - Enter moves on one line: row column\n");
    printf(" - Do not press Enter between row and column\n");
    printf(" - Out-of-range or occupied moves are rejected\n");
    printf(" - Links update automatically after every valid move\n");
    printf(" - Maximum 250 moves this phase\n\n");
    printf("\033[1;33m"" - ANY INPUT AFTER 2 NUMBERS \033[33mi.e. (1 2 3..) etc will be truncated\n\n\033[0m");
    printf("Player O goes first\n");
    printf("Press Enter to begin\n ");
    char x[1024];
    fgets(x,1024,stdin);
    return;
}