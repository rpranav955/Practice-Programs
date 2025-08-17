#include <stdio.h>

void inputArray(int arr[], int num)
{
    printf("Enter numbers:\n");
    for (int i = 0; i < num; i++)
    {
        printf("->");
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    // Input the number of elements to be added into our array from the user.

    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    // Declare the array and add the elements into the array from the user.

    int arr[num];
    inputArray(arr, num);

    printf("\n");
    printf("Array Before Sorting: ");
    printArray(arr, num);
    printf("\n");

    // Sort the array using Selection Sort.

    for (int i = 0; i < num - 1; i++)
    {
        int minKey = i; // Assume index of min. number is i.
        for (int j = i + 1; j < num; j++)
        {
            if (arr[j] < arr[minKey])
            {
                minKey = j; // If there's a number which is smaller than the number we assumed, assign minKey to that index.
            }
        }
        swap(&arr[i], &arr[minKey]);
        printArray(arr, num);
    }

    // Display Sorted array.

    printf("\n");
    printf("Array After Sorting: ");
    printArray(arr, num);
    printf("\n");

    return 0;
}