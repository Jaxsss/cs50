#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            float average = (image[row][col].rgbtBlue + image[row][col].rgbtRed + image[row][col].rgbtGreen) / 3.00;
            int avg = round(average);

            image[row][col].rgbtBlue = avg;
            image[row][col].rgbtRed = avg;
            image[row][col].rgbtGreen = avg;


        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
         int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
         int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
         int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

         image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
         image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
         image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;

        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width/2; col++)
        {
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - col - 1];
            image[row][width - col - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE temp[height][width];

    for(int i = 0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int sumBlue=0;
            int sumRed=0;
            int sumGreen=0;
            float counter=0;

            for(int k=-1; k<2; k++)
            {
                for(int h=-1; h<2; h++)
                {
                    if(i + k < 0 || i + k  > height -1  || j + h < 0 || j + h > width -1)
                    {
                        continue;
                    }

                    sumBlue += image[i+k][j+h].rgbtBlue;
                    sumRed += image[i+k][j+h].rgbtRed;
                    sumGreen += image[i+k][j+h].rgbtGreen;
                    
                    counter++;
                }
            }
            
            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            
            
        }
    }


    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            
        }
    }
    return;
}
