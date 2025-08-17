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

int main()
{

    // Input the number of elements to be added into our array from the user.

    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    // Declare the array and add the elements into the array from the user.

    int arr[num];
    inputArray(arr, num);

    // Ask the number to be found in the array.
    int key, flag = 0;
    printf("The number to be found: ");
    scanf("%d", &key);

    // Find the key using Linear Search and display its index.

    for (int i = 0; i < num; i++)
    {
        if (arr[i] == key)
        {
            printf("'%d' is located at %dth index of the array.\n", key, i);
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        printf("Your required number is not there in the array.\n");
    }

    return 0;
}