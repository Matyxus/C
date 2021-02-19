#include "food.h"

bool hunger(int round, int *tail) {
    if (round % HUNGER_OFFSET == 0) {
        (*tail)++;
        return true;
    }
    return false;
}

void generateFood(int *globl, int *food_x, int *food_y) {
    int currX = *food_x;
    int currY = *food_y;
    int currGlobl = *globl;
    generateCoord(&currGlobl, &currX, X_BORDER); // x
    currX += X_BORDER/2; // x offset to center it (has to be divisible by 3)
    generateCoord(&currGlobl, &currY, Y_BORDER); // y
    currY += Y_BORDER/2+1; // y offset to center it  (has to be divisible by 3)
    while (collision(currX, currY)) {
        generateCoord(&currGlobl, &currX, X_BORDER); // x
        currX += X_BORDER/2; // x offset to center it (has to be divisible by 3)
        generateCoord(&currGlobl, &currY, Y_BORDER); // y
        currY += Y_BORDER/2+1; // y offset to center it (has to be divisible by 3)
    }
    *food_x = currX;
    *food_y = currY;
    *globl = currGlobl;
}

void generateCoord(int *globl, int *coord, int offset) { 
    while (true) {
        int location = myrandom(*globl);
        *coord = (location % offset);
        *globl = location;
        while(((*coord) % 3) != 0){
            (*coord)++;
        }
        if((*coord) == 0){
            (*coord)+=3;
        }else{
            (*coord)-=3;
        }
        return;
    }
}