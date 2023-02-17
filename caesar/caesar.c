#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string encrypt_text(string pText, int key);

int main(int argc, string argv[])
{
    //Program only run with single command-line argument
    if (argc == 2)
    {
        //Check whether argv[1] consists only digits
        int length = strlen(argv[1]);
        string arg = argv[1];
        for (int i = 0; i < length; i++)
        {
            if (isdigit(arg[i]))
            {
                continue;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Converting key string to int
    int key = atoi(argv[1]);

    //Prompt user for plain text
    string pText = get_string("plaintext:  ");

    //Encrypt text
    string cText = encrypt_text(pText, key);
    printf("ciphertext: %s\n", cText);
}

string encrypt_text(string pText, int key)
{
    int length, ascii, cryptedIndex, cryptedAscii;
    length = strlen(pText);
    for (int i = 0; i < length; i++)
    {
        char x = pText[i];
        //Check whether its uppercase
        if (isupper(x))
        {
            ascii = (int)(pText[i]);
            int upperIndex = ascii - 65;
            cryptedIndex = (upperIndex + key) % 26;
            cryptedAscii = cryptedIndex + 65;
            pText[i] = (char)(cryptedAscii);
            continue;
        }
        //Check whether its lowercase
        else if (islower(x))
        {
            ascii = (int)(pText[i]);
            int lowerIndex = ascii - 97;
            cryptedIndex = (lowerIndex + key) % 26;
            cryptedAscii = cryptedIndex + 97;
            pText[i] = (char)(cryptedAscii);
            continue;
        }
    }
    return pText;
}