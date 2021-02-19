#ifndef SNAKE_H
#define SNAKE_H
#include <stdbool.h>
#include "utils.h"
#include "const.h"
#include "food.h"
/*
    Snake's body part, holds its (x, y) coords.
*/
struct Snake {
    int x;
    int y;
};
typedef struct Snake snake;

/*
    Players and Ai's struct, holds their snake's body,
    color of the snake, pointer to head and tail and
    bool if snake has eaten.
*/
struct Player {
    bool eaten;
    int head;
    int tail;
    int color;
    snake *body;
};
typedef struct Player player;

/* 
    First draw to LCD.
*/ 
void initSnake(player curr);

/*  
    Draws snake on new position, if snake didnt eat turns off
    LCD at last tail position, increases tail_pointer -> acts as movement, always draws head
    on new position, if snake did eat, doesn't delete tail, doesn't decrease
    tail_pointer -> increases size.
*/
void drawSnake(player curr, int *tail);

/* 
    Deletes chosen snake from LCD.
*/ 
void deleteSnake(player curr);

/*
    Respawns Ai's snake, first tries initial position if it´s not occupied.
*/
void respawnSnake(snake *body, int head, int *startX, int *startY);

#endif /* SNAKE_H */
