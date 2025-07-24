#include <stdio.h>
#include <stdbool.h>
#define MAXDEGREE 15

int main()
{

    float poly1[MAXDEGREE + 1], poly2[MAXDEGREE + 1];
    int d1 = -1, d2 = -1;

    while (d1 < 1)
    {
        printf("\nEnter the degree of first polynomial: ");
        scanf("%d", &d1);

        if (d1 < 1)
        {
            printf("Degree should be a non-negative integer.\n");
        }
    }

    for (int i = d1; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%f", &poly1[i]);
    }

    while (d2 < 1)
    {
        printf("\nEnter the degree of second polynomial: ");
        scanf("%d", &d2);

        if (d2 < 1)
        {
            printf("Degree should be a non-negative integer.\n");
        }
    }

    for (int i = d2; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%f", &poly2[i]);
    }

    float sumpoly[MAXDEGREE + 1];
    int l;
    l = d1 > d2 ? d1 : d2;

    for (int i = 0; i <= l; i++)
    {
        sumpoly[i] = poly1[i] + poly2[i];
    }

    printf("\nSum of polynomial 1 and 2 is:\n");
    for (int i = l; i > 0; i--)
    {
        if ((int)sumpoly[i] != 0)
        {
            printf(" %.1fx^%d +", sumpoly[i], i);
        }
    }
    printf(" %.1f", sumpoly[0]);
    printf("\n");

    return 0;
}
