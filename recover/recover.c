#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    //opening the file input in argv[1] using the fopen function
    FILE *f = fopen(argv[1], "r");
    FILE *image = NULL;
    //allocating 8 bytes to filename as it would countain 7 + null character
    char *filename = malloc(8);
    uint8_t img[512];
    int count = 0;
    int BLOCK_SIZE = 512;
    //while loop will execture for every block of 512 and would stop as soon as it returns 0
    while (fread(img, BLOCK_SIZE, 1, f))
    {
        //searching for the first 4 bytes in block
        if (img[0] == 0xff && img[1] == 0xd8 && img[2] == 0xff && (img[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(image);
            }
            //sprintf to assign the required filename to found images
            sprintf(filename, "%03i.jpg", count);
            image = fopen(filename, "w");

            if (image == NULL)
            {
                //closing the image file
                fclose(f);
                //freeing memory in filename
                free(filename);
            }
            //adding 1 to counter at the end to create new filename
            count++;
        }
        if (count > 0)
        {
            fwrite(img, BLOCK_SIZE, 1, image);
        }
    }
    //closing the image file
    fclose(image);
    //closing the input file
    fclose(f);
    //freeing memory in filename
    free(filename);

}