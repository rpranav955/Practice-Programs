// quick sort

#include <stdio.h>

int partition(int arr[], int start, int end)
{
    int i = start - 1;
    int pivot = arr[end];

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;

    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    return i;
}

void quicksort(int arr[], int start, int end)
{
    if (end <= start)
    {
        return;
    }

    int pivot = partition(arr, start, end);

    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}

int main()
{
    int arr[] = {10, 5, 1, 9, 4, 2, 8, 3, 7, 6};
    int n = sizeof(arr) / sizeof(int);

    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
