#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //control height (row)
    {
        for (int j = 0; j < width; j++) //control width (column)
        {
            int average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3; //find average of 3 color
            image[i][j].rgbtBlue = average; //set it all the same
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            int buffer = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++) //control height (row)
    {
        for (int j = 0; j < width; j++) //control width (column)
        {
            copy[i][j] = image[i][j]; //make a copy byte
        }
    }

    for (int i = 1; i < height - 1; i++) //control height (row)
    {
        for (int j = 1; j < width - 1; j++) //control width (column)
        {
            int average = (copy[i + 1][j - 1] + copy[i + 1][j] + copy[i + 1][j + 1]\
                            + copy[i][j - 1] + copy[i][j] + copy[i][j + 1]\
                            + copy[i - 1][j - 1] + copy[i - 1][j] + copy[i - 1][j + 1]\
        }
    }

    return;
}
