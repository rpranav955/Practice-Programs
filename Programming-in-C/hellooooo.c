// Program to find the number of digits in a number
#include <stdio.h>

int main()
{
    int x, i, digitcount = 0;
    printf("Enter your number:");
    scanf("%d", &x);

    while (x > 0)
    {
        x /= 10;
        digitcount++;
    }

    printf("The number of digits in the number is: %d", digitcount);

    return 0;
}