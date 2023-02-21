// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    //uint8_t is a type that stores an 8-bit unsigned (i.e., not negative) integer. We can treat each byte of a WAV file’s header as a uint8_t value.
    uint8_t header [HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    //int16_t is a type that stores a 16-bit signed (i.e., positive or negative) integer. We can treat each sample of audio in a WAV file as an int16_t value.
    int16_t buffer;

    //You can then use &buffer as an argument to fread or fwrite to read into or write from the buffer.
    //(Recall that the & operator is used to get the address of the variable.)

    //You may find the documentation for fread and fwrite helpful here.
    //In particular, note that both functions accept the following arguments:
    //ptr: a pointer to the location in memory to store data (when reading from a file) or from which to write data (when writing data to a file)
    //size: the number of bytes in an item of data
    //nmemb: the number of items of data (each of size bytes) to read or write
    //stream: the file pointer to be read from or written to
    //Per its documentation, fread will return the number of items of data successfully read. You may find this useful to check for when you’ve reached the end of the file!

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
