#include <stdio.h>
#include <stdlib.h>
/*
	Grey-scaling ppm image trough convolution.
	((0, -1, 0)
	 (-1, 5, -1)
	 (0, -1, 0))
	Trying to achieve high speed through 
	good cache usage (no vector instructions/parallelism).
	Also create histogram of focused image in grey scale.
	Name of image passed through command line -> argv[1].
*/
int main(int argc, char **argv){
    FILE *orig = NULL;
    FILE *sharp = NULL;
    FILE *txt = NULL;
    char ppm[3];
    int width;
    int height;
    int color;
    orig = fopen(argv[1],"rb");
    sharp = fopen("output.ppm","wb");
    fscanf(orig,"%s %d %d %d \n", ppm, &width, &height, &color);
    int value = 3*width;
    unsigned char *array = malloc(value*sizeof(unsigned char));
    unsigned char *rows = malloc(value*3*sizeof(unsigned char));
    int Y;
    int i, j;
    for (i = 0; i < 3; i++){ // load first three rows
        fread((rows+i*value), 1, value, orig);
    }
    fprintf(sharp,"%s\n", ppm);
    fprintf(sharp,"%d\n", width);
    fprintf(sharp,"%d\n", height);
    fprintf(sharp,"%d\n", color);
    fwrite(rows, 1, value, sharp); // write first row into file
    int hist1 = 0;
    int hist2 = 0;
    int hist3 = 0;
    int hist4 = 0;
    int hist5 = 0;
	// Histogram
    for (i = 0; i < value; i+=3){
        Y = (0.2126 * rows[i] + 0.7152 * rows[i + 1] + 0.0722 * rows[i + 2] + 0.5);
        if (Y < 51){
            hist1++;
        }else if (Y <= 101){
            hist2++;
        }else if (Y <= 152){
            hist3++;
        }else if (Y <= 203){
            hist4++;
        }else{
            hist5++;
        }
    }
    int result;
    int index;
	// Grey-scaling
    for (j = 1; j < height-1; j++){
        // copy first pixel
        index = (j%3)*value;
        array[0] = rows[index];   // R
        array[1] = rows[index+1]; // G
        array[2] = rows[index+2]; // B
        for (i = 3; i < value-3; i++){
            result = -*(rows+((j-1)%3)*value+i) -*(rows+index+i-3) +5*(*(rows+index+i)) -*(rows+index+i+3) -*(rows+((j+1)%3)*value+i);
            if (result < 0){
                result = 0;
            }  else if (result > 255){
                result = 255;
            }
            array[i] = result;
        }
        // copy last pixel
        array[i] = rows[index+i];     // R
        array[i+1] = rows[index+i+1]; // G
        array[i+2] = rows[index+i+2]; // B
		// histogram
        for (i = 0; i < value; i+=3){
            Y = (0.2126 * array[i] + 0.7152 * array[i + 1] + 0.0722 * array[i + 2] + 0.5);
            if (Y < 51){
                hist1++;
            }else if (Y <= 101){
                hist2++;
            }else if (Y <= 152){
                hist3++;
            }else if (Y <= 203){
                hist4++;
            }else{
                hist5++;
            }
        }
        fwrite(array, 1, value, sharp); // output line
        fread((rows+((j-1)%3)*value), 1, value, orig); // load another row
    }
    // copy last row
    for (i = 0; i < value; i++){
        array[i] = rows[i+2*value];
    }
	// histogram
    for (i = 0; i < value; i+=3){
        Y = (0.2126 * array[i] + 0.7152 * array[i+1] + 0.0722 * array[i+2] + 0.5);
        if (Y < 51){
            hist1++;
        }else if (Y <= 101){
            hist2++;
        }else if (Y <= 152){
            hist3++;
        }else if (Y <= 203){
            hist4++;
        }else{
            hist5++;
        }
    }
    fwrite(array, 1, value, sharp);// copy last row
    txt = fopen("output.txt","wb"); // histogram
    fprintf(txt, "%d %d %d %d %d\n", hist1, hist2, hist3, hist4, hist5);
    free(array);
    free(rows);
    fclose(orig);
    fclose(sharp);
    fclose(txt);
    return 0;   
}
