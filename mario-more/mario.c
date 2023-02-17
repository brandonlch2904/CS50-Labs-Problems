#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, space;
    //Get the height of pyramid from user
    do
    {
        height = get_int("Height of pyramid: \n");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i < height + 1; i++)
    {
        //print spaces
        for (space = 0; space < (height - i); space++)
        {
            printf(" ");
        }
        //print left symbol
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        //print 2 spaces in between
        printf("  ");
        //print right symbol
        for (int r = 0; r < i; r++)
        {
            printf("#");
        }
        printf("\n");
    }
}


