#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;
bool is_jpeg(BYTE *buffer);

int main(int argc, char *argv[])
{
    // //check if user give input
    // if (argc != 2)
    // {
    //     printf("Usage: ./recover IMAGE\n");
    //     return 1;
    // }

    //read file
    FILE *input = fopen("card.raw", "r");

    //check if file exist
    if(input == NULL)
    {
        printf("File doesn't exsit\n");
        return 1;
    }



    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    int count = 0;
    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        if (count == 0)
        {
            if(is_jpeg(buffer))
            {
                char *filename = malloc(sizeof(char) * 7);
                
                FILE output = fopen(filename);
            }
        }
    }
}


bool is_jpeg(BYTE *buffer)
{
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
        return false;
    }
    if((buffer[3] & 0xf0) != 0xe0)
    {
        return false;
    }

    free(buffer);

    return true;
}

