#include "helpers.h"
#include "stdio.h"
#include "math.h"

int sobel(int Gx, int Gy);
void copyImage(int height, int width, RGBTRIPLE fromImage[height][width], RGBTRIPLE toImage[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Looping through the height and width
    // and calculating average
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Looping through the height and half of width
    // then mirror the pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2.0; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int count = 0;

            // Looping square 3x3 aroung the pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {

                    // Coords of nearby pixels
                    int ki = i + x;
                    int kj = j + y;

                    // If the nearby pixel is out of bounds
                    if ((ki < 0) || (ki >= height) || (kj < 0) || (kj >= width))
                    {
                        continue;
                    }

                    sumBlue  += image[ki][kj].rgbtBlue;
                    sumGreen += image[ki][kj].rgbtGreen;
                    sumRed   += image[ki][kj].rgbtRed;
                    count += 1;
                }
            }

            blurImage[i][j].rgbtBlue = round((float)sumBlue / count);
            blurImage[i][j].rgbtGreen = round((float)sumGreen / count);
            blurImage[i][j].rgbtRed = round((float)sumRed / count);
        }
    }

    copyImage(height, width, blurImage, image);

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Sobel kernels
    int Gx[3][3] = { { -1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = { { -1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Gx and Gy for RGB
    int GxRed, GxGreen, GxBlue;
    int GyRed, GyGreen, GyBlue;

    // Temp image
    RGBTRIPLE edgeImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            GxBlue = GxGreen = GxRed = 0;
            GyBlue = GyGreen = GyRed = 0;

            // Looping square 3x3 aroung the pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // Coords of nearby pixels
                    int ki = i + x;
                    int kj = j + y;

                    // If the nearby pixel is out of bounds
                    if ((ki < 0) || (ki >= height) || (kj < 0) || (kj >= width))
                    {
                        continue;
                    }

                    // Indexes of Gx Gy kernels
                    int kx = x + 1;
                    int ky = y + 1;

                    GxBlue  += (int)image[ki][kj].rgbtBlue * Gx[kx][ky];
                    GxGreen += (int)image[ki][kj].rgbtGreen * Gx[kx][ky];
                    GxRed   += (int)image[ki][kj].rgbtRed * Gx[kx][ky];

                    GyBlue  += (int)image[ki][kj].rgbtBlue * Gy[kx][ky];
                    GyGreen += (int)image[ki][kj].rgbtGreen * Gy[kx][ky];
                    GyRed   += (int)image[ki][kj].rgbtRed * Gy[kx][ky];
                }
            }

            edgeImage[i][j].rgbtBlue = sobel(GxBlue, GyBlue);
            edgeImage[i][j].rgbtGreen = sobel(GxGreen, GyGreen);
            edgeImage[i][j].rgbtRed = sobel(GxRed, GyRed);
        }
    }

    copyImage(height, width, edgeImage, image);

    return;
}

// Final step of Sobel algorithm:
// calculating the square root of Gx^2 + Gy^2
// Since channel values can only take on integer values from 0 to 255,
// the resulting value is rounded to the nearest integer and capped at 255
int sobel(int Gx, int Gy)
{
    int n = round(sqrt(Gx * Gx + Gy * Gy));
    if (n > 255)
    {
        n = 255;
    }
    return n;
}

// Additional function to copy image
void copyImage(int height, int width, RGBTRIPLE fromImage[height][width], RGBTRIPLE toImage[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            toImage[i][j] = fromImage[i][j];
        }
    }
}
