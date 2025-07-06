#include <stdio.h>
#include <ctype.h>

void printArray(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rotate(int arr[], int n, char d, int cr)
{
    while (cr > 0)
    {
        if (d == 'r')
        {
            int temp = arr[n - 1];
            for (int i = n - 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
            printArray(arr, n);
        }
        else if (d == 'l')
        {
            int temp = arr[0];
            for (int i = 0; i < n; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = temp;
            printArray(arr, n);
        }
        else
        {
            printf("Invalid Direction input!");
            break;
        }
        cr--;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lengthOfArray = sizeof(arr) / sizeof(int);
    char direction;
    int countRotate = 0;

    printf("Enter the direction of rotation (L/R): ");
    scanf("%c", &direction);

    printf("Enter the number of times to be rotated: ");
    scanf("%d", &countRotate);

    printf("\n");
    printf("Array Before Rotation: ");
    printArray(arr, lengthOfArray);
    printf("\n");

    rotate(arr, lengthOfArray, tolower(direction), countRotate);

    printf("\n");
    printf("Array After Rotation: ");
    printArray(arr, lengthOfArray);
    printf("\n");

    return 0;
}