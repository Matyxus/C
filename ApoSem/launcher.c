#include "const.h"
#include "text.h"
#include "move.h"
#include "utils.h"
#include "snake.h"
#include "food.h"
int main(int argc, char const *argv[]) {
    // SETUP
    logo();
    drawBorders(GREEN); // set borders
    char array[] = {'S', 'C', 'O', 'R', 'E', ':',  '0', ' ', ' ', ' ', ' ', '\0'}; // max score is 99999 (impossible to achieve)
    int score = 0;
    int notEaten = 1; // calculated as one movement, serves for indication if snakes recetly eaten
    int food_x = 0; // food_X 
    int food_y = 0; // food_Y
    int firstRand = 7; // first random number (acts as seed also)
    unsigned int mask = 255; // low 8 bits are one's, needed to get the right knob from Qtmips.
    volatile uint32_t *knobs_pointer = (uint32_t *)(SPILED_REG_BASE + SPILED_REG_KNOBS_8BIT_o); // pointer to knobs.
    int green_knob = ((*knobs_pointer) & (mask << 8)) >> 8; // green knob.
    int text_len = textLenght(array); // lenght of chars on LCD screen ("SCORE:") (51)
	fb_text14x16(0, 300, array, GREEN); // first write into screen
    // HUMAN
    snake humanBody[LCD_WIDTH*LCD_HEIGHT/4]; // can hold up to 38 000 moves
    player human;
    human.body = humanBody;
    human.head = 1;
    human.tail = 0;
    human.eaten = false;
    snake initTail = {6+X_BORDER/2, 16+Y_BORDER/2};
    snake initHead = {6+X_BORDER/2, 19+Y_BORDER/2};
    human.body[human.head] = initHead;
    human.body[human.tail] = initTail;
    human.color = GREEN;
    // AI
    snake aiBody[LCD_WIDTH*LCD_HEIGHT/4]; // can hold up to 38 000 moves
    player ai;
    ai.body = aiBody;
    ai.head = 1;
    ai.tail = 0;
    ai.eaten = false;
    int aiStart_x = X_BORDER/2+X_BORDER-15;
    int aiStart_y = (Y_BORDER+Y_BORDER/2)-15;
    snake aiHead = {aiStart_x, aiStart_y};
    ai.body[ai.head] = aiHead;
    snake aiTail = {aiStart_x, aiStart_y-3};
    ai.body[ai.tail] = aiTail;
    ai.color = RED;
    // initial draw to screen
    initSnake(human);
    initSnake(ai);
    generateFood(&firstRand, &food_x, &food_y);
    drawRectangle(food_x, food_y, BLUE, BLUE);
    // main loop
    while(true) {
        moveSnake(human.body, green_knob, &human.head); // move human snake
        notEaten++; // didnt eat
        if (!findDir(ai.body, &ai.head, food_x, food_y)) { // move Ai's snake
            deleteSnake(ai); // delete it 
            score += (ai.head - ai.tail); // add score to player
            updateScore(score, array, text_len); // update it
            respawnSnake(ai.body, ai.head, &aiStart_x, &aiStart_y); // respawn
            ai.head = 1;
            ai.tail = 0;
        }
        // check if player's/Ai's snake has eaten food
        if (human.body[human.head].x == food_x && human.body[human.head].y == food_y) {
            human.eaten = true;
            drawRectangle(food_x, food_y, BLUE, BLACK); // delete food
            score++;
            notEaten = 0; // reset, player's snake has eaten
            updateScore(score, array, text_len);
        } else if (ai.body[ai.head].x == food_x && ai.body[ai.head].y == food_y) {
            ai.eaten = true;
            drawRectangle(food_x, food_y, BLUE, BLACK); // delete food
        }
        if (!human.eaten && hunger(notEaten, &human.tail)) {
            drawRectangle(human.body[human.tail-1].x, human.body[human.tail-1].y, human.color, BLACK); 
        }
        // check for collision, if collision end game
        if (collision(human.body[human.head].x, human.body[human.head].y) ||
            (human.body[human.head].x == ai.body[ai.head].x && 
            human.body[human.head].y == ai.body[ai.head].y) || (human.head-human.tail)==1) {
            drawBorders(BLACK); // delete borders
            deleteSnake(human);
            deleteSnake(ai);
            drawRectangle(food_x, food_y, BLUE, BLACK); // delete food
            fb_text14x16(0, 300, array, BLACK); // delete text
            gameOver(array);
            break;
        }
        // move both snakes
        drawSnake(human, &human.tail);
        drawSnake(ai, &ai.tail);
        if (human.eaten || ai.eaten ) {
            generateFood(&firstRand, &food_x, &food_y);
            drawRectangle(food_x, food_y, BLUE, BLUE);
            ai.eaten = false;
            human.eaten = false;
        }   
        green_knob = ((*knobs_pointer) & (mask << 8)) >> 8;
    }
    while (true)
    {
        // end of program
    }
    return 0;
}
