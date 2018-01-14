#include <cs50.h>
#include <stdio.h>
#include <string.h>

char cryptUpp (char c);
char cryptLow (char c);
char crypt (char c, char min, char max);

int key = 0;

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Wrong number of arguments (expected 1).\n");
        return 1;
    }

   key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = cryptLow(plaintext[i]);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = cryptUpp(plaintext[i]);
        }
    }

    printf("ciphertext: %s\n", plaintext);
}

char cryptUpp (char c)
{
    return crypt(c, 'A', 'Z');
}

char cryptLow (char c)
{
    return crypt(c, 'a', 'z');
}

char crypt (char c, char min, char max)
{
    return (((c - min) + key) % (max-min + 1)) + min;
}