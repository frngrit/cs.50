#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;
bool is_jpeg(BYTE *buffer);
const int BLOCK_SIZE = 512;


int main(int argc, char *argv[])
{
    //check if user give input
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //read file
    FILE *input = fopen("card.raw", "r");

    //check if file exist
    if(input == NULL)
    {
        printf("File doesn't exsit\n");
        return 1;
    }




    BYTE buffer[BLOCK_SIZE];
    int count = 0;
    char *filename = malloc(sizeof(char) * 8);
    FILE *output;


    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        if (count == 0)
        {
            if(is_jpeg(buffer)) //ถ้าเป็นรูปแรกให้สร้างไฟล์
            {
                sprintf(filename, "%i03.jpg",  count);
                output = fopen(filename);
                fwrite(buffer, 1, BLOCK_SIZE, output);
                count += 1;
            }
            else //รูปแรกแต่ไม่ใช่ jpeg ไม่ต้องทำไร
            {

            }
        }
        else
        {
            if(is_jpeg(buffer)) //ไม่ใช่รูปแรกไม่ใช่ jpg ขึ้นไฟล์ใหม่
            {
                fclose(filename);
                sprintf(filename, "%i03.jpg",  count);
                output = fopen(filename);
                count += 1;
            }
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
        fclose(filename);
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

