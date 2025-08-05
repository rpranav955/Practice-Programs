#include <stdio.h>
#define MAX 20

typedef struct {
    int row;
    int col;
    int value;
}Matrix;

void display(Matrix a[], int n){
    printf("\nYour Matrix: \n");
    for(int i = 0; i <= n; i++){
        printf("%d  %d  %d\n", a[i].row, a[i].col, a[i].value);
    }
}

int main(){

    int row, col, count = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int mat[row][col];

    for(int i = 0; i < row; i++){
        printf("Enter the elements of row %d: \n", i+1);
        for(int j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j] != 0){
                count++;
            }
        }
    }
    Matrix new[count + 1];
    new[0].row = row; 
    new[0].col = row; 
    new[0].value = count; 

    // convert

    int z= 1;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] != 0){
                new[z].row = i;
                new[z].col = j;
                new[z++].value = mat[i][j];
            }
        }
    }
    display(new,count);
    return 0;
}
