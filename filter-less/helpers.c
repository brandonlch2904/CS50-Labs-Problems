#include <math.h>
#include "helpers.h"

#define RED 0
#define GREEN 1
#define BLUE 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average_px_val = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = average_px_val;
            image[i][j].rgbtBlue = average_px_val;
            image[i][j].rgbtGreen = average_px_val;
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
            //Sepia Red
            int sepiaRed = round((image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            //Sepia Green
            int sepiaGreen = round((image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            //Sepia Blue
            int sepiaBlue = round((image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.131));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //Assign Sepia value
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
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

//Blur 1 pixel
int get_Blur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_type)
{
    float count = 0;
    int sum = 0;
    for (int row = (i - 1); row <= (i + 1); row++)
    {
        for (int column = (j - 1); column <= (j + 1); column++)
        {
            if (row < 0 || column < 0 || row >= height || column >= width)
            {
                continue;
            }
            if (color_type == RED)
            {
                sum += image[row][column].rgbtRed;
            }
            else if (color_type == GREEN)
            {
                sum += image[row][column].rgbtGreen;
            }
            else
            {
                sum += image[row][column].rgbtBlue;
            }
            count++;
        }
    }
    return round(sum / count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    //Make a copy of original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = get_Blur(i, j, height, width, temp, RED);
            image[i][j].rgbtGreen = get_Blur(i, j, height, width, temp, GREEN);
            image[i][j].rgbtBlue = get_Blur(i, j, height, width, temp, BLUE);
        }
    }
    return;
}
