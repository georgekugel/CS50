#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Define the desired color (here, we choose red)
    RGBTRIPLE new_color = {255, 0, 0};

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // If the pixel is black, change its color to the new color
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                image[i][j] = new_color;
            }
        }
    }
}