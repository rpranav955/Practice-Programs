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

    // convert
    Matrix *result = convert(row, col, mat, count);
    if (result != NULL)
    {
        display(result, count);
        free(result);
    }

    return 0;
}
