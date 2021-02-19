#include "snake.h"

bool findDir(snake *body, int *head, int foodX, int foodY) {
    // find optimal
    int currX = body[(*head)].x;
    int currY = body[(*head)].y;
    if (currX < foodX && !(collision(currX+3, currY))) { // go right
        moveRight(body, head);
        return true;
    }
    if (currX > foodX && !(collision(currX-3, currY))) { // go left
        moveLeft(body, head);
        return true;
    }
    if (currY < foodY && !(collision(currX, currY+3))) { // go down
        moveDown(body, head);
        return true;
    }
    if (currY > foodY && !(collision(currX, currY-3))) { // go up
        moveUp(body, head);
        return true;
    }
    // cant find optimal direction
    if (!(collision(currX+3, currY))) { // go right
        moveRight(body, head);
        return true;
    }
    if (!(collision(currX-3, currY))) { // go left
        moveLeft(body, head);
        return true ;
    }
    if (!(collision(currX, currY+3))) { // go down
        moveDown(body, head);
        return true;
    }
    if (!(collision(currX, currY-3))) { // go up
        moveUp(body, head);
        return true;
    }
    return false; // every direction is blocked
}

void moveSnake(snake *body, int dir, int *head) {
    if (dir < 32 || dir > 223) {
        moveDown(body, head);
    } else if (dir > 32 && dir <  96) {
        moveLeft(body, head);
    } else if (dir > 96 && dir < 160) {
        moveUp(body, head);
    } else {
        moveRight(body, head);
    }
}

void moveRight(snake *body, int *head) {
    snake new = {body[(*head)].x+3, body[(*head)].y};
    (*head)++;
    body[(*head)] = new;
}

void moveLeft(snake *body, int *head) {
    snake new = {body[(*head)].x-3, body[(*head)].y};
    (*head)++;
    body[(*head)] = new;
}

void moveUp(snake *body, int *head) {
    snake new = {body[(*head)].x, body[(*head)].y-3};
    (*head)++;
    body[(*head)] = new;
}

void moveDown(snake *body, int *head) {
    snake new = {body[(*head)].x, body[(*head)].y+3};
    (*head)++;
    body[(*head)] = new;
}
