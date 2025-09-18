#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void printSLL(Node *header)
{
    Node *ptr = header;
    if (!ptr)
    {
        printf("Stack Empty\n");
    }
    else
    {
        while (ptr)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void push(Node **headAddress)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation failed\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (!(*headAddress))
    {
        *headAddress = newNode;
        return;
    }
    newNode->next = *headAddress;
    *headAddress = newNode;
}

int pop(Node **headAddress)
{
    if (*headAddress == NULL)
    {
        printf("Stack UnderFlow\n");
        return 0;
    }
    Node *ptr = *headAddress;
    int item = ptr->data;
    if (!ptr->next)
    {
        *headAddress = NULL;
        free(ptr);
        return item;
    }
    *headAddress = ptr->next;
    free(ptr);
    return item;
}

int peak(Node *header)
{
    if (header == NULL)
    {
        printf("Stack Empty\n");
        return 0;
    }
    return header->data;
}

int main()
{

    Node *header = NULL;
    bool isEnd = false;
    int choice1, result;

    while (!isEnd)
    {
        printf("\n1.\tPush\n2.\tPop\n3.\tPeak\n4.\tPrint Stack\n5.\tStop\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);

        switch (choice1)
        {
        case 1:
            push(&header);
            break;

        case 2:
            result = pop(&header);
            if (result)
            {
                printf("%d\n", result);
            }
            break;

        case 3:
            if (peak(header))
            {
                printf("%d\n", peak(header));
            }
            break;

        case 4:
            printSLL(header);
            break;

        case 5:
            isEnd = true;
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}