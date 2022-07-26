#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


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

    const int FIRST_THREE[3] = {0xff, 0xd8, 0xff}
    uint8_t *buffer;
    for (int i = 0; i < 3; i++)
    {
        fread(buffer, sizeof(uint8_t), 1, input);
        if(buffer != FIRST_THREE[i])
        {
            printf("Not jpeg file.\n");
            return 1;
        }
    }

}