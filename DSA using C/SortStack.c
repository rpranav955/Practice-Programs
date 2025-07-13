#include <stdio.h>

int top1 = -1;
int top2 = -1;
int maxSize = 10;

void push(int stack[], int item, int *top)
{
    if (*top == (maxSize - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++*top] = item;
    }
}

int pop(int stack[], int *top)
{
    if (*top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int item = stack[*top];
        stack[(*top)--] = 0;
        return item;
    }
}

int peek(int stack[], int top)
{
    if (top < 0)
    {
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void printArray(int arr[], int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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
    int stack1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int stack2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int values[maxSize];
    inputArray(values, maxSize);

    for (int i = 0; i < maxSize; i++)
    {
        push(stack1, values[i], &top1);
    }

    printf("Stack Before Sorting: ");
    printArray(stack1, maxSize);
    printf("\n");

    while (top1 != -1)
    {
        int temp = pop(stack1, &top1);

        while (top2 != -1 && peek(stack2, top2) < temp)
        {
            push(stack1, pop(stack2, &top2), &top1);
        }

        push(stack2, temp, &top2);
    }

    printf("Stack After Sorting: ");
    printArray(stack2, maxSize);

    return 0;
}
