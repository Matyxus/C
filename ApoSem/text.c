#include "text.h"

void gameOver(char *array) {
    int len = textLenght("Game Over !");
    fb_text14x16((LCD_WIDTH/2)-(len/2), LCD_HEIGHT/2, "Game Over !", GREEN);
    fb_text14x16((LCD_WIDTH/2)-(len/2), LCD_HEIGHT/2+2*TEXT_HEIGHT, array, GREEN);
}

void logo() {
    int len = textLenght("War snails");
    fb_text14x16((LCD_WIDTH/2)-(len/2), LCD_HEIGHT/6, "War snails", GREEN);
}

void fb_text14x16(int startX, int startY, char *text, int color) {
    int text_height, ch, w, width, n = stringLenght(text), ptr = 0;
    unsigned short mask = 32768; // 1 << 15
    for (text_height = 0; text_height < font_winFreeSystem14x16.height; text_height++) { // iter over text height (constant)
        ptr = text_height * LCD_WIDTH; // pointer
        for (ch = 0; ch < n; ch++) { // iter over number of chars in text array
            width = font_winFreeSystem14x16.width[text[ch] - CHAR_OFFSET];
            for (w = 0; w < width; w++) { // iter over char at index:ch width (variable)
                // check where the char shoud be drawn, comparison between masks ( if bit is set to 1 -> draw)
                if (font_winFreeSystem14x16.bits[16 * (text[ch] - CHAR_OFFSET) + text_height] & (short)(mask >> w)) {
                    if (ptr + LCD_WIDTH + 1 < LCD_WIDTH * LCD_HEIGHT) { // check for valid placement on LCD display.
                        int x = ptr % LCD_WIDTH;
                        pixel(x+startX, ((ptr-x)/LCD_WIDTH)+startY)->r = color;
                        pixel(x+startX, ((ptr-x)/LCD_WIDTH)+startY)->g = color;

                    }
                }
                ptr++; // increase pointer (1 bit in mask of char = 1 pixel)
            }
        }
    }
}

void updateScore(int curr, char *array, int textLen) {
    char empty = '\0';
    char prev[12]; // can hold all int's
    int len = intToChar(curr, prev);
    for (int i = 0; i < len; i++) { // len of array
        if (array[i+NUM_OFFSET] != prev[i]) { // not equal on some index
            empty = array[i+NUM_OFFSET]; // the different digit
            fb_text14x16(textLen+TEXT_HEIGHT*i, 300, &empty, BLACK); // delete what was previously there
            array[i+NUM_OFFSET] = prev[i]; // add the digit back to original
            empty = prev[i]; // digit after curr++
            fb_text14x16(textLen+TEXT_HEIGHT*i, 300, &empty, GREEN); // write the different digit
        }
    }
}
