#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>
#include "pixel.h"
#include "const.h"
#include "font_types.h"
/*
    Draws borderds in center of the screen.
*/
void drawBorders(int color);

/*
    Draws 3x3 rectangle at given (x, y), of given type (fromColor),
    of given color (int color).
*/
void drawRectangle(int x, int y, int fromColor, int color);

/* 
    Generates positive whole number, Source: "glibc (used by GCC)"
    https://en.wikipedia.org/wiki/Linear_congruential_generator
*/ 
int myrandom(int);

/*  
    Transforms int into char array, where each char is one digit.
    https://stackoverflow.com/questions/26688413/how-to-extract-digits-from-a-number-in-c-begining-from-the-most-significant-dig
*/
int intToChar(int iIntToConvert, char *array);

/*
    Return text width of all ascii chars higher than '9' (57).
*/
int textLenght(char *array);

/* 
    Returns lenght of char array.
*/
int stringLenght(char *array);

/* 
    Checks for collision with AI's / Player's snake,
    also looks for border collision (AI cant collide with border).
*/
bool collision(int x, int y);

#endif /* UTILS_H */
