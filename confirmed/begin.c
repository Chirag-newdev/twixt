#include "begin.h"
void initialize()
{
    printf(GREEN
        "  _________    _____  _____      _____      ____  ____    _________   \n"
        " |  _   _  |  |_   _||_   _|    |_   _|    |_  _||_  _|  |  _   _  |  \n"
        " |_/ | | \\_|    | | /\\ | |        | |        \\ \\  / /    |_/ | | \\_|  \n"
        "     | |        | |/  \\| |        | |         > `' <         | |      \n"
        "    _| |_       |   /\\   |       _| |_      _/ /'`\\ \\_      _| |_     \n"
        "   |_____|      |__/  \\__|      |_____|    |____||____|    |_____|    \n"RESET
    );
    printf("\n");
    printf("Player \033[1;94mO\033[0m: Connect " RED "LEFT" RESET " to " BLUE "RIGHT" RESET "\n");
    printf("Player \033[1;94mX\033[0m: Connect " GREEN "TOP" RESET " to " MAGENTA "BOTTOM" RESET "\n");
    printf("\n\nPlayer \033[1;94mO\033[0m goes first\npress Enter to begin the game\n ");
    getchar();
    return;
}