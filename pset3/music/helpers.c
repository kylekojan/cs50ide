// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //assign each side of fraction to variables
    int X = fraction[0] - '0';
    int Y = fraction[2] - '0';
    //divide fraction by 1/8
    int dur = X / Y;
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //notes of an octave
    const string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#", "A", "A#", "B"
                       };


    //biggest problem is the length of char array a - need to find way to explicity declare that as 1 or 2 based off of the note


    int n = strlen(note);
    //printf("n is %i\n", n);
    int len_a = 0;
    int b = 0;
     //need to change to len_a

    if(n == 2)
    {
        len_a = 3;
    }
    else
    {
        len_a = 4;
    }
    char a[len_a];

    //split characters of note into string and int values a and b
    int i = 0;
    for(i = 0; i < n; i++)
    {
        if(isalpha(note[i]) || note[i] == '#' || note[i] == 'b')
        {
           a[i] = note[i];
        }
        else
        {
            b = note[i] - '0';
        }
    }
    a[i] = '\0';

    //printf("a is %s\n", a);
    //printf("b is %i\n", b);

    //assigns number of semitones to integer c
    int q = 0;
    int j = -9;
    while(strcmp(a,NOTES[q]) != 0)
    {
        q++;
        j++;
    }
    int c = j;
    q = 0;

    printf("C is %i\n", c);

    //calculates octave
    int octave = (b - 4) * 12;

    //calculates frequency and returns
    float p = c / (float)12;
    printf("p is %f\n", p);
    int f = round(440 * pow(2.0, ((octave + c)/(float)12)));
    return f;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{

    if(strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
