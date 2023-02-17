#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define block_size 512

typedef uint8_t BYTE;

int isJPEGHeader(BYTE buffer[]);

int main(int argc, char *argv[])
{
    //Accepts only single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *inputFile;
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //Store blocks of 512 bytes in a buffer array
    BYTE buffer[block_size];

    //Count the number of image in the memory
    int img_count = 0;

    //File pointer for recovered image
    FILE *outputFile;

    //Array of 8 for file name
    char fileName[8];


    while (fread(buffer, block_size, 1, inputFile) == 1)
    {
        //Check if 4 starting bytes indicates a JPEG file
        if (isJPEGHeader(buffer) == 1)
        {
            if (img_count > 0)
            {
                fclose(outputFile);
            }

            //Write filename for each JPEG found
            sprintf(fileName, "%03i.jpg", img_count);

            //Open outputFile
            outputFile = fopen(fileName, "w");

            //Write header of JPEG in file
            fwrite(buffer, block_size, 1, outputFile);

            //Count the number of images recovered
            img_count ++;
        }

        else if (img_count > 0)
        {
            //Continue writing after a header is found
            fwrite(buffer, block_size, 1, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int isJPEGHeader(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}