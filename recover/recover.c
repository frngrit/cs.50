#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

check_jpg(FILE *input);
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


}


check_jpg(FILE *input)
{
    BYTE *buffer[4];
    fread();
}
