#ifndef FOOD_H
#define FOOD_H

#include "utils.h"
#include "const.h"
#include <stdbool.h>
/* 
    Generates X or Y coords for food, check if X and Y coord is divisible by 3 (%3 == 0),
    because both snakes start at coords divisible by 3 (can't leave them, since
    they move in +/- 3 as Square(3x3)).
*/
void generateCoord(int *globl, int *coord, int offset);

/*
    Generate food on lcd display, center it into border defined by 
    white line on screen, check if food didn't land on snake.
*/
void generateFood(int *globl, int *food_x, int *food_y);

/* 
    Checks if player's snake has eaten recently *(hunger_offset)*,
    if not, decreases player's snake size by increasing tail pointer.
*/
bool hunger(int round, int *tail); 

#endif /*Food_H*/ 
