#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct
{
    int row;
    int col;
    int value;
} Matrix;

void display(Matrix a[], int n)
{
    printf("\nYour Matrix : \n");
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

Matrix *convert(int row, int col, int a[][col], int count)
{

    Matrix *new = (Matrix *)malloc((count + 1) * sizeof(Matrix));

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    new[0].row = row;
    new[0].col = col;
    new[0].value = count;

    int z = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] != 0)
            {
                new[z].row = i;
                new[z].col = j;
                new[z++].value = a[i][j];
            }
        }
    }

    return new;
}

Matrix *sum(Matrix a[], int n1, Matrix b[], int n2, int *nsum)
{

    Matrix *new = (Matrix *)malloc((n1 + n2) * sizeof(Matrix));

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    new[0].col = a[0].col;
    new[0].row = a[0].row;

    int i = 1, j = 1, z = 1;
    while (i <= n1 && j <= n2)
    {
        if (a[i].row == b[j].row && a[i].col == b[j].col)
        {
            new[z].col = a[i].col;
            new[z].row = a[i].row;
            if (a[i].value + b[j].value != 0)
            {
                new[z].value = a[i].value + b[j].value;
            }
            i++;
            j++;
            z++;
        }
        else if (a[i].row < b[j].row)
        {
            new[z].col = a[i].col;
            new[z].row = a[i].row;
            new[z].value = a[i].value;
            i++;
            z++;
        }
        else
        {
            new[z].col = b[j].col;
            new[z].row = b[j].row;
            new[z].value = b[j].value;
            j++;
            z++;
        }
    }
    while (i <= n1)
    {
        new[z].col = a[i].col;
        new[z].row = a[i].row;
        new[z].value = a[i].value;
        i++;
        z++;
    }
    while (j <= n2)
    {
        new[z].col = b[j].col;
        new[z].row = b[j].row;
        new[z].value = b[j].value;
        j++;
        z++;
    }

    new[0].value = z - 1;
    *nsum = z - 1;

    return new;
}

int main()
{

    int row, col, count1 = 0, count2 = 0, nsum = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int mat1[row][col], mat2[row][col];

    printf("\nEnter the elements of First Matrix:\n");
    for (int i = 0; i < row; i++)
    {
        printf("Enter the elements of row %d: \n", i + 1);
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat1[i][j]);
            if (mat1[i][j] != 0)
            {
                count1++;
            }
        }
    }

    printf("\nEnter the elements of Second Matrix:\n");
    for (int i = 0; i < row; i++)
    {
        printf("Enter the elements of row %d: \n", i + 1);
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat2[i][j]);
            if (mat2[i][j] != 0)
            {
                count2++;
            }
        }
    }

    // convert 1
    Matrix *StructM1 = convert(row, col, mat1, count1);
    printf("\n1:");
    display(StructM1, count1);

    // convert 2
    Matrix *StructM2 = convert(row, col, mat2, count2);
    printf("\n2:");
    display(StructM2, count2);

    Matrix *result = sum(StructM1, count1, StructM2, count2, &nsum);
    printf("\nSum:");
    display(result, nsum);

    free(StructM1);
    free(StructM2);
    free(result);
    return 0;
}
