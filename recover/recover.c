#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

bool is_jpeg(FILE *input);
FILE copy_phto(FILE *input);
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if user give input
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //read file
    FILE *input = fopen(argv[1], "r");

    //check if file exist
    if(file == NULL)
    {
        printf("File doesn't exsit\n");
        return 1;
    }

    if(is_jpeg)
    {
        FILE *output = fopen()
    }



}


bool is_jpeg(FILE *input)
{
    BYTE *buffer = malloc(sizeof(BYTE) * 4);
    fread(buffer, sizeof(BYTE), 4, input);
    if(buffer[0] != 0xff)
    {
        return false;
    }
    if(buffer[1] != 0xd8)
    {
        return false;
    }
    if(buffer[2] != 0xff)
    {
        return false
    }
    if(buffer[3] & 0xf0 != 0xe0)
    {
        return false
    }
    free(buffer);
    return true
}

void copy_photo(FILE *input, FILE *output)
{
    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {

    }
}