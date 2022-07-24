#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // control height (row)
    {
        for (int j = 0; j < width; j++) // control width (column)
        {
            int average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3; // find average of 3 color
            image[i][j].rgbtBlue = average;                                                         // set it all the same
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
            sepiaRed = sepiaRed > 255 ? 255 : sepiaRed;
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            sepiaBlue = sepiaBlue > 255 ? 255 : sepiaBlue;

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
    for (int i = 0; i < height; i++) // control height (row)
    {
        for (int j = 0; j < width; j++) // control width (column)
        {
            copy[i][j] = image[i][j]; // make a copy byte
        }
    }

    // inner-square (has 9 around them) or the star
    //  -----
    //  -***-
    //  -***-
    //  -***-
    //  -----
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int average_red = 0, average_green = 0, average_blue = 0;
            for (int m = 1; m > -2; m--)
            {
                // row of around
                for (int n = 1; n > -2; n--)
                {
                    // col of around
                    average_red += copy[i + m][j + n].rgbtRed;
                    average_green += copy[i + m][j + n].rgbtGreen;
                    average_blue += copy[i + m][j + n].rgbtBlue;
                }
            }
            image[i][j].rgbtRed = average_red / 9;
            image[i][j].rgbtGreen = average_green / 9;
            image[i][j].rgbtBlue = average_blue / 9;
        }
    }

    // left-top corner (0, 0)
    int average_red = 0, average_green = 0, average_blue = 0;
    for (int i = 0; i < 2; i++)
    {
        // pattern for row 0 -> 1

        for (int j = 0; j < 2; j++)
        {
            // pattern for col 0 -> 1
            average_red += copy[i][j].rgbtRed;
            average_green += copy[i][j].rgbtGreen;
            average_blue += copy[i][j].rgbtBlue;
        }
    }
    image[0][0].rgbtRed = average_red / 9;
    image[0][0].rgbtGreen = average_green / 9;
    image[0][0].rgbtBlue = average_blue / 9;

    // right-top corner (0 , width - 1)
    average_red = 0, average_green = 0, average_blue = 0;
    for (int i = 0; i > -2; i--)
    {
        // pattern for row 0 -> -1
        for (int j = -1; j < 1; j++)
        {
            // pattern for col -1 -> 0
            average_red += copy[i][width - 1 + j].rgbtRed;
            average_green += copy[i][width - 1 + j].rgbtGreen;
            average_blue += copy[i][width - 1 + j].rgbtBlue;
        }
    }
    image[0][width - 1].rgbtRed = average_red / 9;
    image[0][width - 1].rgbtGreen = average_green / 9;
    image[0][width - 1].rgbtBlue = average_blue / 9;

    // left-bottom corner (height - 1, 0)
    average_red = 0, average_green = 0, average_blue = 0;
    for (int i = -1; i < 1; j++)
    {
        // pattern for row -1 -> 0
        for (int j = 0; j < 2; j++)
        {
            // pattern for row 0 -> 1
            average_red += copy[height - 1 + i][j].rgbtRed;
            average_green += copy[height - 1 + i][j].rgbtGreen;
            average_blue += copy[height - 1 + i][j].rgbtBlue;
        }
    }
    image[height - 1][0].rgbtRed = average_red / 9;
    image[height - 1][0].rgbtGreen = average_green / 9;
    image[height - 1][0].rgbtBlue = average_blue / 9;

    // left-bottom corner (height - 1, width - 1)
    average_red = 0, average_green = 0, average_blue = 0;
    //pattern for row -1 -> 0
    for (int i = -1; i < 1; i++)
    {
        //pattern for col -1 -> 0
        for (int j = -1; j < 1; j++)
        {
            average_red += copy[height - 1 + i][width - 1 + j].rgbtRed;
            average_green += copy[height - 1 + i][width - 1 + j].rgbtGreen;
            average_blue += copy[height - 1 + i][width - 1 + j].rgbtBlue;
        }
    }
    image[height - 1][width - 1].rgbtRed = average_red / 9;
    image[height - 1][width - 1].rgbtGreen = average_green / 9;
    image[height - 1][width - 1].rgbtBlue = average_blue / 9;

    //upper-row
    // -**-
    // ----
    // ----
    // ----
    //pattern for row 0 -> 1
    //start from (0, 1) to (0, width -2)
    for (int m = 1; m < width - 1; m++)
    {
        average_red = 0, average_green = 0, average_blue = 0;
        for (int i = 0; i < 2; i++)
        {
            //pattern for col -1 -> 1
            for (int j = -1; j < 2; j++)
            {
                average_red += copy[0 + i][m + j].rgbtRed;
                average_green += copy[0 + i][m + j].rgbtGreen;
                average_blue += copy[0 + i][m + j].rgbtBlue;
            }
        }
    }

    //lower-row
    // ----
    // ----
    // ----
    // -**-
    //pattern for row -1 -> 0
    for (int i = -1, i < 1; i++)
    {
        //pattern for 
        for (int j = -1;
    }
    return;
}
