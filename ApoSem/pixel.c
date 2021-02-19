#include "pixel.h"

struct px *pixel(int x, int y) {
	return (volatile struct px*)LCD_FB_START + x + (y * LCD_WIDTH);
}