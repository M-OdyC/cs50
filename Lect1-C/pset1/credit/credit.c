#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool checkIsValidInput (string cardNumber);
string checkCardType (string cardNumber);
bool isVisa (string cardNumber);
bool isAmex (string cardNumber);
bool isMaster (string cardNumber);
int getFirstNumbers (string cardNumber);
bool checksum (string cardNumber);

int main (void)
{
    //prompt for input and expect a credit card number
    string cardType = "";
    char cardC [30];

    do
    {
        sprintf(cardC, "%lld", get_long_long("Insert a credit card number: "));
        cardType = checkCardType (cardC);
    }
    while (strlen(cardType) == 0);

    if (!checksum(cardC))
    {
        cardType = "INVALID\n";
    }
    printf("%s", cardType);
}

string checkCardType (string cardNumber)
{
    if (checkIsValidInput(cardNumber))
    {
        int size = strlen(cardNumber);

        if (size == 13)
        {
            if (isVisa(cardNumber)) return "VISA\n";
        }
        else if (size == 15)
        {
            if (isAmex(cardNumber)) return "AMEX\n";
        }
        else if (size == 16)
        {
            if (isVisa(cardNumber)) return "VISA\n";
            else if (isMaster(cardNumber)) return "MASTERCARD\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    return "";
}

bool checkIsValidInput (string cardNumber)
{
    int size = strlen(cardNumber);

    for (int i = 0; i < size; i ++)
    {
        if (cardNumber[i] < '0' || cardNumber[i] > '9') return false;
    }
    return true;
}

int getFirstNumbers (string cardNumber)
{
    char s [] = {cardNumber[0],cardNumber[1]};

    return atoi(s);
}

bool isVisa (string cardNumber)
{
    if ((cardNumber[0] - '0') == 4) return true;
    return false;
}

bool isMaster (string cardNumber)
{
    if (getFirstNumbers(cardNumber) >= 51 && getFirstNumbers(cardNumber) <= 55) return true;
    return false;
}

bool isAmex (string cardNumber)
{
    if (getFirstNumbers(cardNumber) == 34 || getFirstNumbers(cardNumber) == 37) return true;
    return false;
}

bool checksum (string cardNumber)
{
    int sum1 = 0;
    int sum2 = 0;

    for (int i = strlen(cardNumber), j=0; i == 0; i--)
    {
        if ((j+1) % 2 == 0)
        {
            int num = cardNumber[i] - '0';
            num *= 2;
            if (num > 9)
            {
                num = 1 + num % 10;
            }
            sum2 += num;
        }
        else
        {
           sum1+= cardNumber[i]  - '0';
        }
        j++;
    }

    if ((sum1 + sum2) % 10 == 0) return true;
    else return false;
}