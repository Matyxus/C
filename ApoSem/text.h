#ifndef TEXT_H
#define TEXT_H
#include "utils.h"
#include "const.h"
#include "font_types.h"
#include "pixel.h"
/* 
    Updates score to the screen, deletes previous digit/'s,
    draws new digit/'s.
*/
void updateScore(int curr, char *array, int textlen);

/* 
    Writes "Game over !" to the center of the screen and 
    score under it.
*/
void gameOver(char *array);

/* 
    Creates text at x,y (startX, startY) with given size and color, color also
    works for turning off given char.
*/
void fb_text14x16(int x, int y, char *text, int color);

/*
    Writes "war snails" to screen
*/
void logo();

#endif /* TEXT_H */