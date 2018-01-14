// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

int letter_to_semitones(char note);
double semitones_freq(int semitones);
double octave_multiplier(int octave);

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int num = ((strtok(fraction, "/")[0]) - '0');
    int den = ((strtok(NULL, "/")[0]) - '0');
    return num * (8 / den);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double curFreq;
    int octave, semitones;

    if (strlen(note) > 2)
    {
        octave = note[2] - '0';
        if (note[1] == '#')
            semitones = 1;
        else
            semitones = -1;
    }
    else
    {
        octave = note[1] - '0';
        semitones = 0;
    }

    semitones += letter_to_semitones(note[0]);
    curFreq = semitones_freq(semitones);

    return (int)(round(curFreq * octave_multiplier(octave)));
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int letter_to_semitones(char note)
{
    switch (note)
    {
        case 'A': return 0;
        case 'B': return 2;
        case 'C': return -9;
        case 'D': return -7;
        case 'E': return -5;
        case 'F': return -4;
        case 'G': return -2;
    }
    return 0;
}

double semitones_freq(int semitones)
{
    return 440.0 * (pow(2.0, ((double)semitones)/12.0));
}

double octave_multiplier(int octave)
{
    if (octave == 4) return 1.0;
    double mult = ((double)octave) - 4.0;
    if (mult > 0)
        return mult * 2.0;
    else
        return 1.0 / (fabs(mult) * 2.0);
}
