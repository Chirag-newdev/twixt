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

    printf("Player \033[1;94mO\033[0m: Connect " RED "LEFT" RESET " to " BLUE "RIGHT" RESET "\n");
    printf("Player \033[1;94mX\033[0m: Connect " GREEN "TOP" RESET " to " MAGENTA "BOTTOM" RESET "\n\n");

    printf("Rules and Input:\n");
    printf(" - Enter moves as: row column\n");
    printf(" - Use a single line (no separate prompts)\n");
    printf(" - Out-of-range moves are rejected\n");
    printf(" - Links and pins update automatically\n");
    printf(" - Max 40 moves this phase\n");
    printf(" - Close the window to quit\n\n");

    printf("Player \033[1;94mO\033[0m goes first\n");
    printf("Press Enter to begin the game\n ");

    getchar();
    return;
}