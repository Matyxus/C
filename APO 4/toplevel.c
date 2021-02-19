#include "subroutine.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int toplevel_fnc(void){
	int counter = 0;
	char val;
	char tempval;
	while (read(0, &val, 1)==1){
		tempval = ((subroutine_fnc(val) << 24) >> 24);
		if (val != tempval){
			counter++;
		}
		if (write(1, &tempval, 1) < 0){
			return counter;
		}
	}
	return counter;
}
