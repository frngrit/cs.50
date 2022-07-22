// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

void copy_header(FILE *input, FILE *output);
void multiplier(FILE *input, FILE *output, float factor);

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
    copy_header(input, output);
    // TODO: Read samples from input file and write updated data to output file
    multiplier(input, output, factor);
    // Close files
    fclose(input);
    fclose(output);
}

void copy_header(FILE *input, FILE *output)
{
    //initial array of header
    uint8_t header[HEADER_SIZE];
    //read and put header in header array
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    //wirte header in output file
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);
}

void multiplier(FILE *input, FILE *output, float factor)
{
    int check;
    do
    {
        //initial buffer to store a sample
        int16_t buffer;
        //read sample from input file
        fread(&buffer, sizeof(int16_t), 1, input);
        buffer *= factor;
        //write a modified sample into output file
        check = fwrite(&buffer, sizeof(int16_t), 1, input);
    }
    while (check != 0);
}