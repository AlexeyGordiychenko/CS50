#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// second implementation with reading 4 bytes instead of 1
// this allow to check JPEG by: (buffer[0] & 0xf0ffffff) == 0xe0ffd8ff (see below)
typedef uint32_t  DWORD;
const int BLOCK_SIZE = 512 / sizeof(DWORD);

int newImage(FILE **jpeg_image, int idx);

int main(int argc, char *argv[])
{
    // Check correct arguments
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    // Open the raw file
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Counter for filenames
    int i = 0;

    // Initialize null jpeg image and the buffer for 512 bytes
    FILE *jpeg_image = NULL;
    DWORD buffer[BLOCK_SIZE];

    while (fread(&buffer, sizeof(DWORD), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // Checking JPEG header
        // Apparently you don't need to check the 4th byte, check is ok with it
        if ((buffer[0] & 0xf0ffffff) == 0xe0ffd8ff)
        {
            // Close the previous image, if exists
            if (jpeg_image != NULL)
            {
                fclose(jpeg_image);
            }

            // Create a new image with the next filename
            if (!newImage(&jpeg_image, i))
            {
                printf("Could not create file.\n");
                return 1;
            }
            i++;
        }

        // Write to the output file, if exists
        if (jpeg_image != NULL)
        {
            fwrite(&buffer, sizeof(DWORD), BLOCK_SIZE, jpeg_image);
        }

    }

    // Closing both files
    fclose(raw_file);
    fclose(jpeg_image);
}

// Creates a new jpeg file with the filename 'xxx.jpg'
// xxx is the index of the file
int newImage(FILE **jpeg_image, int idx)
{
    char filename[8];
    sprintf(filename, "%03i.jpg", idx);
    *jpeg_image = fopen(filename, "w");
    if (jpeg_image == NULL)
    {
        return 0;
    }
    return 1;
}