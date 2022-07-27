#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

bool is_jpeg(FILE *input);
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



    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    int count = 0;
    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        if(is_jpeg(buffer))
        {
            if(count == 0)
            {
                char *file_name = malloc(sizeof(char) * 7); //create name for output file
                sprintf(file_name, "%i03.jpg", count);
                FILE *output = fopen(file_name, "w");   //open output file for writing
                fwrite(buffer, 1, BLOCK_SIZE, output);  //write those chunk of data into output file
                count += 1;
            }
            else
            {
                fclose(output);
            }
        }
        else
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);  //write those chunk of data into output file
        }
    }

}


bool is_jpeg(FILE *buffer)
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
        return false
    }
    if(buffer[3] & 0xf0 != 0xe0)
    {
        return false;
    }

    free(buffer);

    return true;
}

