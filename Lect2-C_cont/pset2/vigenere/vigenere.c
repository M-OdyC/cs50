#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool inputIsValid(int nArgs, string str);

int main (int argc, string argv [])
{
    if (!inputIsValid(argc, argv[1]))
    {
        printf("Please insert a valid input\n");
        return 1;
    }

    string txt = get_string("Plaintext: ");
    int numKeys = strlen(argv[1]);
    int keys [numKeys];

    for (int i = 0; i < numKeys; i++)
    {
        int letter = argv[1][i];
        if (isupper(letter)) letter -= 'A';
        if (islower(letter)) letter -= 'a';
        keys[i] = letter;
    }

    for (int i = 0, j = 0, l = strlen(txt); i < l; i++)
    {
        if (isalpha(txt[i]))
        {
            if (isupper(txt[i])) txt[i] = (((txt[i] - 'A') + keys[j]) % ('Z'-'A' + 1)) + 'A';
            if (islower(txt[i])) txt[i] = (((txt[i] - 'a') + keys[j]) % ('z'-'a' + 1)) + 'a';

            if (j < (numKeys-1)) j++;
            else j = 0;
        }
    }

    printf("ciphertext: %s\n", txt);
}

bool inputIsValid(int nArgs, string str)
{
    if (nArgs != 2) return false;

    for (int i = 0, l = strlen(str); i < l; i++)
    {
        if (!isalpha(str[i])) return false;
    }
    return true;
}