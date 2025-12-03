#ifndef Gl_H
#define Gl_H
#define SIZE 24 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
extern char arr[SIZE][SIZE];
extern bool state[SIZE+5][SIZE+5];
extern char connected[SIZE][SIZE];
extern char links[SIZE][SIZE][8];
#endif