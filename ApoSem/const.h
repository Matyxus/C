#ifndef CONST_H
#define CONST_H
/*
    LCD.
*/
#define LCD_FB_START    0xffe00000
#define LCD_FB_END		0xffe4afff
#define LCD_WIDTH	480
#define LCD_HEIGHT	320
#define X_BORDER LCD_WIDTH/2
#define Y_BORDER LCD_HEIGHT/2
#define BORDER_SIZE (X_BORDER*Y_BORDER)
#define SIZE (LCD_WIDTH*LCD_HEIGHT)
/*
    Colors.
*/
#define GREEN 61
#define BLUE  60
#define RED   30
#define BLACK 0
/*
    Random Generator.
*/
#define MULTIPLIER 1103515245
#define INCREMENT 12345
#define MODULUS 0x7fffffff // 2^31-1
/* 
    Knobs.
*/
#define SPILED_REG_KNOBS_8BIT_o 0x024
#define SPILED_REG_BASE 0xffffc100
#define CHAR_OFFSET 0x20
/*  
    Text.
*/
#define NUM_OFFSET 6 // Location of first number in char array.
#define TEXT_HEIGHT 8 // Height of text char's.

#define HUNGER_OFFSET 150

#endif /* CONST_H */