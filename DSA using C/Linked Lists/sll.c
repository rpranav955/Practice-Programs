#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
        printf("Your SLL is empty\n");
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

void addNodeAtFront(Node **headAddress)
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

void addNodeAtEnd(Node **headAddress)
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

void addNodeAtIndex(Node *header, int position)
{
    if (!header)
    {
        printf("Your SLL is empty\n");
        return;
    }
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation failed\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    Node *ptr = header;

    while (position != 1)
    {
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            break;
        }
        position--;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void delNodeAtFront(Node **headAddress)
{
    if (*headAddress == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *ptr = *headAddress;
    if(!ptr->next){
        *headAddress = NULL;
        free(ptr);
        return;
    }
    *headAddress = ptr->next;
    free(ptr);
}

void delNodeAtEnd(Node **headAddress)
{
    if (*headAddress == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *ptr = *headAddress;
    if(!(ptr->next)){
        *headAddress = NULL;
        free(ptr);
        return;
    }
    Node *prev;
    while (ptr->next)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
}

void delNodeAtIndex(Node *header, int position)
{
    if (header == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *ptr = header;
    Node *prev;
    while (position > 1)
    {
        if (ptr->next == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        prev = ptr;
        ptr = ptr->next;
        position--;
    }
    prev->next = ptr->next;
    free(ptr);
}

int main()
{
    Node *header = NULL;
    bool isEnd = false;
    int choice1, choice2, position;
    while (!isEnd)
    {
        printf("\n1.\tCreate a new node\n2.\tDelete a node\n3.\tPrint the node\n4.\tStop\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            printf("\n1.\tAdd node at front\n2.\tAdd node at end\n3.\tAfter a given position\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                addNodeAtFront(&header);
                break;
            case 2:
                addNodeAtEnd(&header);
                break;
            case 3:
                printf("\nEnter the position after which the new node should be added: ");
                scanf("%d", &position);
                addNodeAtIndex(header, position);
                break;

            default:
                printf("Invalid Choice\n");
                break;
            }

            break;
        case 2:
            printf("\n1.\tDelete node at front\n2.\tDelete node at end\n3.\tDelete at a position\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice2);
            int position;

            switch (choice2)
            {
            case 1:
                delNodeAtFront(&header);
                break;
            case 2:
                delNodeAtEnd(&header);
                break;
            case 3:
                printf("\nEnter the position of the node to be deleted: ");
                scanf("%d", &position);
                delNodeAtIndex(header, position);
                break;

            default:
                printf("Invalid Choice\n");
                break;
            }

            break;
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
