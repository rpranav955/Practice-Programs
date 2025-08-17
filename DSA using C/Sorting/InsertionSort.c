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

    // Sort the array using Insertion Sort.

    for (int i = 1; i < num; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        printArray(arr, num);
    }

    // Display the Sorted array.

    printf("\n");
    printf("Array After Sorting: ");
    printArray(arr, num);
    printf("\n");

    return 0;
}