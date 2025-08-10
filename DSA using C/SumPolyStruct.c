#include <stdio.h>
#define MAXSIZE 20

typedef struct
{
    float coeff;
    int exp;
} Term;

Term sum[MAXSIZE];
int nsum = 0;

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
        printf("%.2f x^%d", a[i].coeff, a[i].exp);
        if (i != n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void Sum(Term a[], int n1, Term b[], int n2)
{
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (a[i].exp == b[j].exp)
        {
            sum[nsum].exp = a[i].exp;
            sum[nsum].coeff = a[i].coeff + b[j].coeff;
            i++;
            j++;
            nsum++;
        }
        else if (a[i].exp > b[j].exp)
        {
            sum[nsum++] = a[i++];
        }
        else
        {
            sum[nsum++] = b[j++];
        }
    }
    while (i < n1)
    {
        sum[nsum++] = a[i++];
    }
    while (j < n2)
    {
        sum[nsum++] = b[j++];
    }
}

int main()
{

    Term poly1[MAXSIZE], poly2[MAXSIZE], result[MAXSIZE];
    int n1, n2;

    printf("\nEnter your first polynomial: \n");
    n1 = readPoly(poly1);

    printf("\nEnter your second polynomial: \n");
    n2 = readPoly(poly2);

    Sum(poly1, n1, poly2, n2);

    printf("\nSum of Polynomial 1 and 2: \n");
    printPoly(sum, nsum);

    return 0;
}
