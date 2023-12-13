#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // loop for each row
    {
        for (int j = 0; j < width; j++) // loop for each pixel
        {
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtBlue = 0xc8; //changing Blue component to 0xc8
            }
        }
    }
}
