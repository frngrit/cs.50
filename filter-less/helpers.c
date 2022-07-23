#include "helpers.h"
#include <math.h>

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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaRed = sepiaRed > 255? 255: sepiaRed;
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaGreen = sepiaGreen > 255? 255: sepiaGreen;
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            sepiaBlue = sepiaBlue > 255? 255: sepiaBlue;


            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE buffer = image[i][j];
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

    //top-left avereage
    int average_red = 0, average_green = 0, average_blue = 0;
    average_red += copy[0][0].rgbtRed + copy[0][1].rgbtRed + copy[1][0].rgbtRed + copy[1][1].rgbtRed;
    average_green += copy[0][0].rgbtGreen + copy[0][1].rgbtGreen + copy[1][0].rgbtGreen + copy[1][1].rgbtGreen;
    average_blue += copy[0][0].rgbtBlue + copy[0][1].rgbtBlue + copy[1][0].rgbtBlue + copy[1][1].rgbtBlue;
    image[0][0].rgbtRed = average_red / 4;
    image[0][0].rgbtGreen = average_green / 4;
    image[0][0].rgbtBlue = average_blue / 4;
    average_red = 0, average_green = 0, average_blue = 0;

    //top-right avereage
    average_red += copy[0][width - 1].rgbtRed + copy[0][width - 2].rgbtRed + copy[1][width - 1].rgbtRed + copy[1][width - 2].rgbtRed;
    average_green += copy[0][width - 1].rgbtGreen + copy[0][width - 2].rgbtGreen + copy[1][width - 1].rgbtGreen + copy[1][width - 2].rgbtGreen;
    average_blue += copy[0][width - 1].rgbtBlue + copy[0][width - 2].rgbtBlue + copy[1][width - 1].rgbtBlue + copy[1][width - 2].rgbtRed;
    image[0][width - 1].rgbtRed = average_red / 4;
    image[0][width - 1].rgbtGreen = average_green / 4;
    image[0][width - 1].rgbtBlue = average_blue / 4;
    average_red = 0, average_green = 0, average_blue = 0;

    //bottom-left avereage
    average_red += copy[height - 1][0].rgbtRed + copy[height - 2][0].rgbtRed + copy[height - 1][1].rgbtRed + copy[height - 2][1].rgbtRed;
    average_green += copy[height - 1][0].rgbtGreen + copy[height - 2][0].rgbtGreen + copy[height - 1][1].rgbtGreen + copy[height - 2][1].rgbtGreen;
    average_blue += copy[height - 1][0].rgbtBlue + copy[height - 2][0].rgbtBlue + copy[height - 1][1].rgbtBlue + copy[height - 2][1].rgbtBlue;
    image[height - 1][0].rgbtRed = average_red / 4;
    image[height - 1][0].rgbtGreen = average_green / 4;
    image[height - 1][0].rgbtBlue = average_blue / 4;
    average_red = 0, average_green = 0, average_blue = 0;

    //bottom-right avereage
    average_red += copy[height - 1][width - 1].rgbtRed + copy[height - 1][width - 2].rgbtRed \
    + copy[height - 2][width - 1].rgbtRed + copy[height - 2][width - 2].rgbtRed;
    average_green += copy[height - 1][width - 1].rgbtGreen + copy[height - 1][width - 2].rgbtGreen \
    + copy[height - 2][width - 1].rgbtGreen + copy[height - 2][width - 2].rgbtGreen;
    average_blue += copy[height - 1][width - 1].rgbtBlue + copy[height - 1][width - 2].rgbtBlue \
    + copy[height - 2][width - 1].rgbtBlue + copy[height - 2][width - 2].rgbtBlue;
    image[height - 1][width - 1].rgbtRed = average_red / 4;
    image[height - 1][width - 1].rgbtGreen = average_green / 4;
    image[height - 1][width - 1].rgbtBlue = average_blue / 4;

    for (int i = 1; i < height - 1; i++) //control height (row)
    {
        for (int j = 1; j < width - 1; j++) //control width (column)
        {
            int average_red = 0, average_green = 0, average_blue = 0;

            average_red += copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed \
            + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed \
            + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed;//Red
            average_green += copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen \
            + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen \
            + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen ;//Green
            average_blue += copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue
            + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue \
            + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue ;//Bule

            image[i][j].rgbtRed = average_red / 9;
            image[i][j].rgbtGreen = average_green / 9;
            image[i][j].rgbtBlue = average_blue / 9;
        }
    }

    //first-row inner
    for (int j = 1; j < width - 1; j++)
    {
        int average = copy[0][j] + copy[0][j - 1] + copy[0][j + 1] + copy[1][j - 1] + copy[1][j] + copy[1][j + 1];
        image[0][j] = average / 6;
    }

    //last-row inner
    for (int j = 1; j < width - 1; j++)
    {
        int average = copy[height - 1][j] + copy[height - 1][j - 1] + copy[height - 1][j + 1]\
        + copy[height - 2][j - 1] + copy[height - 2][j] + copy[height - 2][j + 1];
        image[height - 1][j] = average / 6;
    }

    //left-col inner
    for (int i = 1; i < height - 1; i++)
    {
        int average = copy[i][0] + copy[i - 1][0] + copy[i - 1][1] + copy[i][1] + copy[i + 1][0] + copy[i + 1][1];
        image[i][0] = average / 6;
    }

    //right-col inner
    for (int i = 1; i < height - 1; i++)
    {
        int average = copy[i][width - 1] + copy[i - 1][width - 1] + copy[i - 1][width - 2] \
         + copy[i][width - 2] + copy[i + 1][width - 1] + copy[i + 1][width - 2];
        image[i][width - 1] = average / 6;
    }

    return;
}
