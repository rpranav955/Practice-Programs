#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct
{
    float coeff;
    int exp;
} Term;

int readPoly(Term a[])
{
    int n;
    printf("Enter the number of non-zero terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%f", &a[i].coeff);
        printf("Enter the exponent of x: ");
        scanf("%d", &a[i].exp);
    }

    return n;
}

void printPoly(Term a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].exp == 0)
        {
            printf("%.1f", a[i].coeff);
        }
        else if (a[i].exp == 1)
        {
            printf("%.1f x", a[i].coeff);
        }
        else
        {
            printf("%.1f x^%d", a[i].coeff, a[i].exp);
        }

        if (i != n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

Term *Sum(Term a[], int n1, Term b[], int n2, int *nsum)
{

    Term *sum = (Term *)malloc((n1 + n2) * sizeof(Term));

    if (sum == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int i = 0, j = 0, z = 0;

    while (i < n1 && j < n2)
    {
        if (a[i].exp == b[j].exp)
        {
            if (a[i].coeff + b[j].coeff != 0)
            {
                sum[z].exp = a[i].exp;
                sum[z].coeff = a[i].coeff + b[j].coeff;
                z++;
            }
            i++;
            j++;
        }
        else if (a[i].exp > b[j].exp)
        {
            sum[z++] = a[i++];
        }
        else
        {
            sum[z++] = b[j++];
        }
    }
    while (i < n1)
    {
        sum[z++] = a[i++];
    }
    while (j < n2)
    {
        sum[z++] = b[j++];
    }

    *nsum = z;

    return sum;
}

int main()
{

    Term poly1[MAXSIZE], poly2[MAXSIZE];
    int n1, n2, nsum;

    printf("\nEnter your first polynomial: \n");
    n1 = readPoly(poly1);

    printf("\nEnter your second polynomial: \n");
    n2 = readPoly(poly2);

    Term *result = Sum(poly1, n1, poly2, n2, &nsum);

    printf("\nSum of Polynomial 1 and 2: \n");
    printPoly(result, nsum);

    return 0;
}
