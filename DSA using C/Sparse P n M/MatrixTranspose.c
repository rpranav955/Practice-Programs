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
    printf("\nYour Matrix: \n");
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

Matrix *Convert(int row, int col, int a[][col], int count)
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

Matrix *Transpose(Matrix a[])
{
    Matrix *new = (Matrix *)malloc((a[0].value + 1) * sizeof(Matrix));

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    new[0].col = a[0].row;
    new[0].row = a[0].col;
    new[0].value = a[0].value;

    for (int i = 1; i <= a[0].value; i++)
    {
        new[i].col = a[i].row;
        new[i].row = a[i].col;
        new[i].value = a[i].value;
    }

    Matrix temp;

    for (int i = 1; i <= a[0].value; i++)
    {
        for (int j = 1; j <= a[0].value - i; j++)
        {
            if (new[j + 1].row < new[j].row)
            {
                temp = new[j];
                new[j] = new[j + 1];
                new[j + 1] = temp;
            }
        }
    }

    return new;
}

int main()
{

    int row, col, count = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int mat[row][col];

    for (int i = 0; i < row; i++)
    {
        printf("Enter the elements of row %d: \n", i + 1);
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] != 0)
            {
                count++;
            }
        }
    }

    // Convert
    Matrix *mStruct = Convert(row, col, mat, count);
    display(mStruct, count);

    // Transpose
    printf("\nTranspose of the above Matrix:\n");
    Matrix *transpose = Transpose(mStruct);
    display(transpose, count);

    free(mStruct);
    free(transpose);
    return 0;
}
