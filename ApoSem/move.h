#ifndef MOVE_H
#define MOVE_H

#include "utils.h"
#include "snake.h"

/* 
    Determines where is knob pointed to and moves snake in
    that direction.(Since knob is 0-255 -> 266, angle of one
    movement is 64).
*/
void moveSnake(snake *body, int dir, int *head);

/* 
    Generates move for AI's snake, tries to find optimal path, if such a path
    puts snake into collision, snake changes direction.
*/
bool findDir(snake *body, int *head, int foodX, int foodY);

/* 
    Move snake to right by increasing it's head "x" coord by 3.
*/
void moveRight(snake *body, int *head);

/* 
    Move snake to right by decreasing it's head "x" coord by 3.
*/
void moveLeft(snake *body, int *head);

/* 
    Move snake to right by decreasing it's head "y" coord by 3.
*/
void moveUp(snake *body, int *head);

/* 
    Move snake to right by increasing it's head "y" coord by 3.
*/
void moveDown(snake *body, int *head);
#endif /* MOVE_H */
