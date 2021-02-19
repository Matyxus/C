#ifndef PIXEL_H
#define PIXEL_H
#include "const.h"
/*
	Struct which holds RGB values of LED.
*/
struct px {
	unsigned r : 5;
	unsigned g : 6;
	unsigned b : 5;
} __attribute__((packed));
typedef struct px px;

/*
	Turns on led depending on its coord (x, y) and
	chosen color, used as pixel(x, y)->(r/g/b) = *value*,
	where value increases brightness of chosen color.
*/
struct px *pixel(int x, int y);

#endif /* PiXEL_H */
