// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <math.h>
// #include <string.h>
// #include <windows.h>
// #define RED     "\033[31m"
// #define GREEN   "\033[32m"
// #define YELLOW  "\033[33m"
// #define BLUE    "\033[34m"
// #define MAGENTA "\033[35m"
// #define RESET   "\033[0m"
// #define SIZE 24 
// #define tw "\n\033[1B\033[1D"
// #define kw "\033[1B\033[1D"
// char arr[SIZE][SIZE]={0};
// bool state[SIZE+1][SIZE+1]={0};
// void init()
// {
//         printf(GREEN
//         "  _________    _____  _____      _____      ____  ____    _________   \n"
//         " |  _   _  |  |_   _||_   _|    |_   _|    |_  _||_  _|  |  _   _  |  \n"
//         " |_/ | | \\_|    | | /\\ | |        | |        \\ \\  / /    |_/ | | \\_|  \n"
//         "     | |        | |/  \\| |        | |         > `' <         | |      \n"
//         "    _| |_       |   /\\   |       _| |_      _/ /'`\\ \\_      _| |_     \n"
//         "   |_____|      |__/  \\__|      |_____|    |____||____|    |_____|    \n"RESET
//     );
//     printf("\n");
//     printf("Player \033[1;94mO\033[0m: Connect " RED "LEFT" RESET " to " BLUE "RIGHT" RESET "\n");
//     printf("Player \033[1;94mX\033[0m: Connect " GREEN "TOP" RESET " to " MAGENTA "BOTTOM" RESET "\n");
//     printf("\n\nPlayer \033[1;94mO\033[0m goes first\npress Enter to begin the game\n ");
//     getchar();
//     char(*ptr)[] = arr;
//     memset(arr,'.',sizeof(arr));
//     return;
// }
// void print(char* s)
// {
//     for(int i=0;i<SIZE-1;i++)
//     {
//         printf("%c   ",s[i]);
//     }
//     printf("%c",s[SIZE-1]);
//     return;
// }
// void display()
// {
//     system("cls");
//     printf("   ");
//     for(int i=0;i<SIZE;i++)printf("%d%s",i,i<10?"   ":"  ");
//     printf("\n");
//     for (int i = 0; i < SIZE; i++)
//     {
//         printf("%d%s",i,i<10?"  ":" ");
//         print(arr[i]);
//         printf("\n\n");
//     }
//     return;
// }
// int pin(char z)
// {
//     int x,y;
//     printf("Player :%c, please enter row and comumn of your move in format:\"row column\"\n\033[2K",z);
//     if(scanf(" %d %d",&x,&y)!=2)return -10;
//     if((x<0||x>=SIZE) || (y<0||y>=SIZE))
//     {
//         printf("\0337");
//         printf("\0338");
//         printf("\033[3A");
//         printf("out of bounds\n");
//         return -2;
//     }
//     if(arr[x][y]=='.')
//     {
//         arr[x][y]=z;
//         printf("\0337");
//         printf("\033[r\033[H");
//         printf("\033[%d;%dH", 2*x+2,4+y*4);
//         printf("%c",z);
//         fflush(stdout);
//         printf("\0338");
//         printf("\033[2A");
//         return (x)*SIZE  +  (y);
//     }
//     else
//     {
//         printf("\033[2A");
//         return -1;
//     }
// }
// void block(int x,int y,int dx,int dy)
// {
//     if(abs(dx)==1)state[x+(dx>0)][y+(dy>0)]=state[x+(dx>0)][y+(dy>0)+dy/2]=1;
//     else if(abs(dx)==2)state[x+(dx>0)-(dx<0)][y+(dy>0)]=state[x+(dx>0)*dx][y+(dy>0)]=1;
//     return;
// }
// bool check(int x,int y,int dx,int dy)
// {
//     if(abs(dx)==1)
//         {
//             if(state[x+(dx>0)][y+(dy>0)] || state[x+(dx>0)][y+(dy>0)+dy/2])
//             {
//                 return 0;
//             }
//         }
//     else if(abs(dx)==2)
//     {
//         if(state[x+(dx>0)-(dx<0)][y+(dy>0)] || state[x+(dx>0)*dx][y+(dy>0)])
//         {
//             return 0;
//         }
//     }
//     block(x, y, dx, dy);
//     return true;
// }
// void viable(int x,int y)
// {
//     char a[8][2]={{x+2,y+1},{x+1,y+2},{x+2,y-1},{x+1,y-2},{x-1,y-2},{x-2,y-1},{x-2,y+1},{x-1,y+2}};
//     for(int i=0;i<8;i++)
//     {
//         char x1=a[i][0];
//         char y1=a[i][1];
//         int dx=x1-x,dy=y1-y;
//         char z= dx*dy>0?'\\':'/';
//         if(arr[x][y]!=arr[x1][y1])continue;
//         if(!check(x,y,dx,dy))continue;
//         if(fabs(dx)==1)
//         {
//             printf("\0337");
//             printf("\033[%d;%dH", (x+x1)+2,1+(y+y1)*2);
//             printf("%c-----%c",z,z);
//             fflush(stdout);
//             printf("\0338");
//         }
//         else
//         {
//             printf("\0337");
//             printf("\033[%d;%dH", (x+x1),4+(y+y1)*2);
//             printf("%c"kw"|"kw"|"kw"|"kw"%c",z,z);
//             fflush(stdout);
//             printf("\0338");
//         }
//     }
//     return;
// }
// int main()
// {
//     init();
//     bool x=0;
//     int i=10;
//     display();
//     while(i--)
//     {
//         int t=-1;
//         while(t==-1)
//         {
//             t=pin(x?'X':'O');
//             if(t==-10)return 0;
//         }
//         x=!x;
//         viable(t/SIZE,t%SIZE);
//     }
//     return 0;
// }