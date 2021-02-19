#include "utils.h"

void drawBorders(int color) {
    // first row
    for (int i = 0; i < X_BORDER; i++) {
        pixel(X_BORDER/2+i, Y_BORDER/2)->r = color;
        pixel(X_BORDER/2+i, Y_BORDER/2)->g = color;
        pixel(X_BORDER/2+i, Y_BORDER/2)->b = color;
    }
    // down from left corner
    for (int i = 0; i < Y_BORDER; i++) {
        pixel(X_BORDER/2, Y_BORDER/2+i)->r = color;
        pixel(X_BORDER/2, Y_BORDER/2+i)->g = color;
        pixel(X_BORDER/2, Y_BORDER/2+i)->b = color;

    }
    // down from right corner
    for (int i = 0; i < Y_BORDER; i++) {
        pixel(X_BORDER/2+X_BORDER, Y_BORDER/2+i)->r = color;
        pixel(X_BORDER/2+X_BORDER, Y_BORDER/2+i)->g = color;
        pixel(X_BORDER/2+X_BORDER, Y_BORDER/2+i)->b = color;
    }
    // second row
    for (int i = 0; i < X_BORDER+1; i++) {
        pixel(X_BORDER/2+i, Y_BORDER*2 -Y_BORDER/2)->r = color;
        pixel(X_BORDER/2+i, Y_BORDER*2 -Y_BORDER/2)->g = color;
        pixel(X_BORDER/2+i, Y_BORDER*2 -Y_BORDER/2)->b = color;
    }
}

int stringLenght(char *array) {
    int len = 0;
    while (*(array + len) != '\0') {
        len++;
    }
    return len;
}

int intToChar(int rmdr, char *array) {
    int counter = 0;
    int rm10;
    int dvsr;
    int quot;
    rm10 = rmdr/10;
    dvsr = 1;
    while(dvsr <= rm10)
        dvsr *= 10;
    while(dvsr) {
        quot = rmdr / dvsr;
        array[counter] = quot + '0';
        rmdr %= dvsr;
        dvsr /= 10;
        counter++;
    }
    return counter;
}

int textLenght(char *array) {
    int width = 0;
    for (int i = 0; i < stringLenght(array); i++) {   
        if (array[i] > '9') {
            width += font_winFreeSystem14x16.width[array[i] - CHAR_OFFSET];
        }
    }
    return width;
}

bool collision(int x, int y) {
    if (pixel(x, y)->g == 0 && pixel(x, y)->r == 0 &&
       (x > X_BORDER/2 && x < X_BORDER/2+X_BORDER-1) &&
        (y > Y_BORDER/2 && y <  Y_BORDER*2 -Y_BORDER/2-1)) { 
        return false;
    }
    return true;
}

void drawRectangle(int x, int y, int fromColor, int color) {
    switch (fromColor) {
        case RED:
            // first row
            pixel(x  , y)->r = color;
            pixel(x-1, y)->r = color;
            pixel(x+1, y)->r = color;
            // second row
            pixel(x  , (y+1))->r = color;
            pixel(x-1, (y+1))->r = color;
            pixel(x+1, (y+1))->r = color;
            // third row
            pixel(x  , (y-1))->r = color;
            pixel(x-1, (y-1))->r = color;
            pixel(x+1, (y-1))->r = color;
            return;
        case GREEN:
            // first row
            pixel(x  , y)->g = color;
            pixel(x-1, y)->g = color;
            pixel(x+1, y)->g = color;
            // second row
            pixel(x  , (y+1))->g = color;
            pixel(x-1, (y+1))->g = color;
            pixel(x+1, (y+1))->g = color;
            // third row
            pixel(x  , (y-1))->g = color;
            pixel(x-1, (y-1))->g = color;
            pixel(x+1, (y-1))->g = color;
            return;
        case BLUE:
            // first row
            pixel(x  , y)->b = color;
            pixel(x-1, y)->b = color;
            pixel(x+1, y)->b = color;
            // second row
            pixel(x  , (y+1))->b = color;
            pixel(x-1, (y+1))->b = color;
            pixel(x+1, (y+1))->b = color;
            // third row
            pixel(x  , (y-1))->b = color;
            pixel(x-1, (y-1))->b = color;
            pixel(x+1, (y-1))->b = color;
            return;
        default:
            return;
    }
}

int myrandom(int seed) {
    return ((seed * MULTIPLIER + INCREMENT) & MODULUS);
}
