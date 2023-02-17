#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int letters_count(string Text);
int words_count(string Text);
int sentences_count(string Text);
int count_grade(int letters, int words, int sentences);


int main(void)
{
    //Get text
    string Text = get_string("Text: ");
    //Number of letters
    int letters = letters_count(Text);
    //Number of words
    int words = words_count(Text);
    //Number of strings
    int sentences = sentences_count(Text);
    //Counting grades
    int value = count_grade(letters, words, sentences);
    if (value < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (value > 0 && value < 16)
    {
        printf("Grade %i\n", value);
    }
    else
    {
        printf("Grade 16+\n");
    }

}

int letters_count(string Text)
{
    int length, letters;
    letters = 0;
    length = strlen(Text);
    for (int i = 0; i < length; i++)
    {
        if (isupper(Text[i]) || islower(Text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int words_count(string Text)
{
    int words, length;
    words = 1;
    length = strlen(Text);
    for (int i = 0; i < length; i++)
    {
        if (isspace(Text[i]))
        {
            words += 1;
        }
    }
    return words;
}

int sentences_count(string Text)
{
    int sentences, length;
    sentences = 0;
    length = strlen(Text);
    for (int i = 0; i < length; i++)
    {
        int ascii = (int)(Text[i]);
        if (ascii == 46 || ascii == 63 || ascii == 33)
        {
            sentences += 1;
        }

    }
    return sentences;
}

int count_grade(int letters, int words, int sentences)
{
    string grade;
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int value = round(index);
    return value;
}