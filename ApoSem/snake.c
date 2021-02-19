#include "snake.h"
void initSnake(player curr) {
    drawRectangle(curr.body[curr.head].x, curr.body[curr.head].y, curr.color, curr.color);
    drawRectangle(curr.body[curr.tail].x, curr.body[curr.tail].y, curr.color, curr.color);   
}

void drawSnake(player curr, int *tail) { 
    if (!curr.eaten) {
        drawRectangle(curr.body[curr.tail].x , curr.body[curr.tail].y, curr.color, BLACK);
        (*tail)++;
    }
    drawRectangle(curr.body[curr.head].x , curr.body[curr.head].y, curr.color, curr.color);
}

void deleteSnake(player curr) {
    for (int i = 0; i < (curr.head - curr.tail)+1; i++) {
        drawRectangle(curr.body[curr.head-i].x, curr.body[curr.head-i].y, curr.color, BLACK);
    }   
}

void respawnSnake(snake *body, int head, int *startX, int *startY) {
    int rand = 150; 
    if (!collision(*startX, *startY)) {
        snake aiHead = {*startX, *startY};
        body[1] = aiHead;
        snake aiTail = {*startX, (*startY)-3};
        body[0] = aiTail;
    } else {
        generateFood(&rand, startX, startY);
        snake aiHead = {*startX, *startY};
        snake aiTail = {*startX, (*startY)-3};
        body[1] = aiHead;
        body[0] = aiTail;
    }
}
