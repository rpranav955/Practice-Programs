#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

void printDLL(Node *header)
{
    if (!header)
    {
        printf("Empty List\n");
        return;
    }
    while (header)
    {
        printf("%d ", header->data);
        header = header->next;
    }
    printf("\n");
}

void createNodeAtFront(Node **headAddress, Node **tailAddress)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation failed\n");
        return;
    }

    int item;
    printf("Enter data: ");
    scanf("%d", &item);

    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*headAddress == NULL)
    {
        *headAddress = newNode;
        *tailAddress = newNode;
        return;
    }
    newNode->next = *headAddress;
    (*headAddress)->prev = newNode;
    *headAddress = newNode;
}

void createNodeAtEnd(Node **headAddress, Node **tailAddress)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation failed\n");
        return;
    }

    int item;
    printf("Enter data: ");
    scanf("%d", &item);

    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*headAddress == NULL)
    {
        *headAddress = newNode;
        *tailAddress = newNode;
        return;
    }
    newNode->prev = *tailAddress;
    (*tailAddress)->next = newNode;
    *tailAddress = newNode;
}

void createNodeAtPos(Node **headAddress, Node **tailAddress)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation failed\n");
        return;
    }

    int pos;
    printf("Enter position to where the node should be placed: ");
    scanf("%d", &pos);
    int item;
    printf("Enter data: ");
    scanf("%d", &item);

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    while (pos >= 1)
    {
        pos--;
    }
}

void delNodeAtFront(Node **headAddress)
{
    if (!*headAddress)
    {
        printf("Empty List\n");
        return;
    }
    Node *ptr = *headAddress;
    *headAddress = ptr->next;
    free(ptr);
}

void delNodeAtEnd(Node **tailAddress)
{
    if (!*tailAddress)
    {
        printf("Empty List\n");
        return;
    }
    Node *ptr = *tailAddress;
    while (ptr->next)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    *tailAddress = prev;
    free(ptr);
}

int main()
{

    Node *header = NULL;
    Node *tail = NULL;
    bool isEnd = false;
    int choice1, choice2;

    while (!isEnd)
    {

        printf("\n Double Linked List\n");
        printf("\n1.\tCreate a new node\n2.\tDelete a node\n3.\tPrint the node\n4.\tStop\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);

        switch (choice1)
        {
        case 1:
            printf("\n1.\tAt Front\n2.\tAt End\n3.\tAt a Position\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                createNodeAtFront(&header, &tail);
                break;
            case 2:
                createNodeAtEnd(&header, &tail);
                break;
            case 3:
                createNodeAtPos(&header, &tail);
                break;
            default:
                printf("Invalid Choice\n");
            }

            break;
        case 2:
            printf("\n1.\tAt Front\n2.\tAt End\n3.\tAt a Position\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                delNodeAtFront(&header);
                break;
            case 2:
                delNodeAtEnd(&header, &tail);
                break;
            case 3:

                break;
            default:
                printf("Invalid Choice\n");
            }

            break;
        case 3:
            printDLL(header);
            break;
        case 4:
            isEnd = true;
            break;
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}