#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //1st for loop for the image first row of pixels
    for (int i = 0; i < height; i++)
    {
        //2nd loop for each pixel in row of pixels in image
        for (int j = 0; j < width; j++)
        {
            //creating an int variable to replace the pixels
            int rgbt;

            //averaging the value of pixels allows to assign them all the same value (hence create a grayscale)
            rgbt = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            //here we assing each pixel in image with th same integer for red, green and blue
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = rgbt;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //1st for loop for the image first row of pixels
    for (int i = 0; i < height; i++)
    {
        //2nd loop for each pixel in row of pixels in image
        for (int j = 0; j < width; j++)
        {
            //creating three integers that will be used to replace the pixel's red, green and blue value after sepia algorithm
            int sepiaRed;
            int sepiaGreen;
            int sepiaBlue;

            //using the formula for the sepia filter to change the value for the pixels
            sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));

            //if statement in case any of the sepiaRed, sepiaGreen, and sepiaBlue exceel the max of 255 value per pixel
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //setting the pixel's red, green and blue color = to the integers stored in the sepiaRed, sepiaGreen and sepiaBlue
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
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                // store the current element in a temporary variable
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                // swap the current element with the corresponding element from the end
                image[i][j] = image[i][width - (j + 1)];
                // set the corresponding element from the end to the temporary variable
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
        else if (width % 2 != 0)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                // store the current element in a temporary variable
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                // swap the current element with the corresponding element from the end
                image[i][j] = image[i][width - (j + 1)];
                // set the corresponding element from the end to the temporary variable
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // store the current element in a temporary variable
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //create three values where to store the sum of all red, green, blue values of the pixels sourrounding the pixel [i][j]
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            // the count variable will determin how many pixels are sourrounding the pixel image[i][j]
            float count = 0;

            //this for loops make sure that edge cases are take into account in case a certian pixel does not have 9 pixels around
            //first one is for the rows
            for (int row = -1; row < 2; row++)
            {
                //second one for pixels
                for (int pix = -1; pix < 2; pix++)
                {
                    // these conditions avoid that pixels on the edges of the image look for 9 pixels around
                    if (row + i < 0 || row + i > (height - 1))
                    {
                        continue;
                    }
                    if (pix + j < 0 || pix + j > (width - 1))
                    {
                        continue;
                    }
                    //here adding all the values for the pixels around the image[i][j] for all red, green and blue
                    totalRed = totalRed + image[i + row][j + pix].rgbtRed;
                    totalGreen = totalGreen + image[i + row][j + pix].rgbtGreen;
                    totalBlue = totalBlue + image[i + row][j + pix].rgbtBlue;
                    //adding 1 to counter as it will be used for division
                    count++;
                }
            }
            //temp variable becomes the total / count rounded to nearest integer
            temp[i][j].rgbtRed = round(totalRed / count);
            temp[i][j].rgbtGreen = round(totalGreen / count);
            temp[i][j].rgbtBlue = round(totalBlue / count);
        }
    }
    //in this last for loop, the temp variable values for red, green and blue are assigned to image [i][j] red green and blue
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
