#include <stdio.h>

void inputArray(int arr[], int num)
{
    printf("Enter elements:\n");
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

double findMean(int arr[], int num)
{
    double sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += arr[i];
    }
    return (sum / num);
}

double findMedian(int arr[], int num)
{
    if (num % 2 == 0)
    {
        return ((double)arr[num / 2] + (double)arr[(num / 2) - 1]) / 2;
    }
    else
    {
        return arr[(num / 2)];
    }
}

int findMode(int arr[], int num)
{
    int maxCount = 0;
    int mode;

    for (int i = 0; i < num; i++)
    {
        int count = 0;
        for (int j = 0; j < num; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            mode = arr[i];
        }
        return mode;
    }
}

int main()
{

    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int arr[num];
    inputArray(arr, num);

    double mean = findMean(arr, num);
    double median = findMedian(arr, num);
    int mode = findMode(arr, num);

    printf("\n");
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);
    printf("\n");

    return 0;
}