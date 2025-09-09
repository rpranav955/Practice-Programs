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

void printDLLrev(Node *tail)
{
    if (!tail)
    {
        printf("Empty List\n");
        return;
    }
    while (tail)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
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
    printf("Enter position after which the node should be placed: ");
    scanf("%d", &pos);
    int item;
    printf("Enter data: ");
    scanf("%d", &item);
    newNode->data = item;

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    
    Node *ptr = *headAddress; 
    
    while (pos != 1)
    {
    	  ptr = ptr->next;
    	  if (ptr->next == NULL)
        {
        		printf("Invalid Position");
            return;
        }
        pos--;
    }
    
    (ptr->next)->prev = newNode;
    newNode->next = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    
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
    (ptr->next)->prev = NULL;
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
    
    (ptr->prev)->next = NULL;
    *tailAddress = ptr->prev;
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
        printf("\n1.\tCreate a new node\n2.\tDelete a node\n3.\tPrint the node\n4.\tPrint the node in reverse\n5.\tStop\n");
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
                delNodeAtEnd(&tail);
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
            printDLLrev(tail);
            break;

        case 5:
            isEnd = true;
            break;
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}
