#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void printCLL(Node *header)
{
    if (!header)
    {
        printf("\nEmpty CLL\n");
        return;
    }

    Node *ptr = header;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != header);
    printf("\n");
}

void createNodeAtFront(Node **header)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    printf("\nData: ");
    scanf("%d", &newNode->data);

    if (!*header)
    {
        *header = newNode;
        newNode->next = *header;
        return;
    }

    Node *ptr = *header;

    do
    {
        ptr = ptr->next;
    } while (ptr->next != *header);

    newNode->next = *header;
    *header = newNode;
    ptr->next = *header;
}

void createNodeAtEnd(Node **header)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    printf("\nData: ");
    scanf("%d", &newNode->data);

    if (!*header)
    {
        *header = newNode;
        newNode->next = *header;
        return;
    }

    Node *ptr = *header;

    do
    {
        ptr = ptr->next;
    } while (ptr->next != *header);

    ptr->next = newNode;
    newNode->next = *header;
}

void createNodeAfterPosition(Node **header)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    printf("\nData: ");
    scanf("%d", &newNode->data);

    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("\nInvalid Position\n");
        return;
    }

    Node *ptr = *header;
    while (pos > 1)
    {
        if (ptr->next == *header)
        {
            printf("\nInvalid Position\n");
            return;
        }
        ptr = ptr->next;
        pos--;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

void delNodeFront(Node **header)
{
    if (!*header)
    {
        printf("Empty CLL\n");
        return;
    }

    if ((*header)->next == *header)
    {
        free(*header);
        *header = NULL;
        return;
    }

    Node *ptr = *header;
    do
    {
        ptr = ptr->next;
    } while (ptr->next != *header);

    ptr->next = (*header)->next;
    free(*header);
    *header = ptr->next;
}

void delNodeEnd(Node **header)
{
    if (!*header)
    {
        printf("Empty CLL\n");
        return;
    }

    if ((*header)->next == *header)
    {
        free(*header);
        *header = NULL;
        return;
    }

    Node *ptr = *header, *prev;
    do
    {
        prev = ptr;
        ptr = ptr->next;
    } while (ptr->next != *header);

    free(ptr);
    prev->next = *header;
}

void delNodeAtPos(Node **header)
{
    if (!*header)
    {
        printf("Empty CLL\n");
        return;
    }

    int pos;
    Node *ptr = *header, *prev;

    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos <= 1)
    {
        printf("\nInvalid Position\n");
        return;
    }

    while (pos > 1)
    {
        if (ptr->next == *header)
        {
            printf("\nInvalid Position\n");
            return;
        }
        prev = ptr;
        ptr = ptr->next;
        pos--;
    }

    prev->next = ptr->next;
    free(ptr);
}

int main()
{
    Node *header = NULL;
    bool isEnd = false;
    int choice1, choice2;

    printf("Circular Linked List\n");

    while (!isEnd)
    {
        printf("\n1.\tCreate a node\n2.\tDelete a node\n3.\tPrint List\n4.\tStop\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        switch (choice1)
        {
        case 1:
            printf("1.\tAt Front\n2.\tAt End\n3.\tAfter a Position\n");
            printf("Enter your choice: ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                createNodeAtFront(&header);
                break;
            case 2:
                createNodeAtEnd(&header);
                break;
            case 3:
                createNodeAfterPosition(&header);
                break;
            default:
                printf("Invalid choice\n");
            }

            break;
        case 2:

            if (!header)
            {
                printf("\nEmpty CLL\n");
            }
            else
            {
                printf("1.\tFrom Front\n2.\tFrom End\n3.\tFrom a Position\n");
                printf("Enter your choice: ");
                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    delNodeFront(&header);
                    break;
                case 2:
                    delNodeEnd(&header);
                    break;
                case 3:
                    delNodeAtPos(&header);
                    break;
                default:
                    printf("Invalid Choice\n");
                }
            }

            break;
        case 3:
            printCLL(header);
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