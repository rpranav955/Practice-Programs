#include <stdio.h>

int answer[20];

void printArray(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int intersection(int s1[], int n1, int s2[], int n2)
{
    int count = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (s1[i] == s2[j])
            {
                answer[count] = s1[i];
                count++;
            }
        }
    }
    return count;
}

int main()
{

    int s1[] = {1, 2, 3, 4}, s2[] = {3, 4, 5};
    int ls1 = sizeof(s1) / sizeof(int), ls2 = sizeof(s2) / sizeof(int);

    printf("\n");
    printf("s1: ");
    printArray(s1, ls1);
    printf("s2: ");
    printArray(s2, ls2);

    printf("\n");
    printf("Intersection of s1 and s2: ");

    int n = intersection(s1, 4, s2, 3);

    printArray(answer, n);

    printf("\n");

    return 0;
}