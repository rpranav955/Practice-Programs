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
        printf("Queue Empty\n");
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

void enqueue(Node **headAddress)
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

    Node *ptr = *headAddress;

    if (!(*headAddress))
    {
        *headAddress = newNode;
        return;
    }

    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

int dequeue(Node **headAddress)
{
    if (*headAddress == NULL)
    {
        printf("Queue Underflow\n");
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

int main()
{
    Node *header = NULL;
    bool isEnd = false;
    int choice1, result;

    while (!isEnd)
    {
        printf("\n1.\tEnqueue\n2.\tDequeue\n3.\tPrint Queue\n4.\tStop\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);

        switch (choice1)
        {
        case 1:
            enqueue(&header);
            break;

        case 2:
            result = dequeue(&header);
            if (result)
            {
                printf("%d\n", result);
            }
            break;

            // case 3:
            //     if (peak(header))
            //     {
            //         printf("%d\n", peak(header));
            //     }
            //     break;

        case 3:
            printSLL(header);
            break;

        case 4:
            isEnd = true;
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}