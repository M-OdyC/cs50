#include <cs50.h>
#include <stdio.h>

void printSpaces(int n);
void printBlocks(int n);

int main (void)
{
    //prompt user for input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height >= 24);

    //draw pyramid
    for (int i = 0; i < height; i++)
    {
        printSpaces(height - i - 1);
        printBlocks(i + 1);
        printf("\n");
    }
}

void printSpaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void printBlocks(int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }
    printf("  ");
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }
}