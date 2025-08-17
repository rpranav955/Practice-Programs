#include <stdio.h>
#include <stdbool.h>

int top = -1;
int maxSize = 10;

void push(int stack[], int item)
{
    if (top == (maxSize - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = item;
    }
}

int pop(int stack[])
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int item = stack[top--];
        stack[top + 1] = 0;
        return item;
    }
}

int peek(int stack[])
{
    if (top < 0)
    {
        printf("Stack Empty\n");
        return 0;
    }
    else
    {
        return stack[top];
    }
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int stack[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool run = true;

    while (run)
    {
        printf("\n");
        printf("Your Choices: \n");
        printf("\n");
        printf("\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Print Stack\n\t5.Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter your number: ");
            int item;
            scanf("%d", &item);
            push(stack, item);
            break;

        case 2:
            int popped = pop(stack);
            if (popped == -1)
            {
                break;
            }
            else
            {
                printf("%d popped\n", popped);
                break;
            }

        case 3:
            printf("%d is at top\n", peek(stack));
            break;

        case 4:
            printf("Your Stack: ");
            printArray(stack, maxSize);
            break;

        case 5:
            run = false;
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
