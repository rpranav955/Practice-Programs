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
    //  aaaaaaaaaaaaaaaaaaaaaaaaaaa
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

    printf("Data: ");
    scanf("%d", &newNode->data);

    if (!*header)
    {
        *header = newNode;
        newNode->next = *header;
        return;
    }

    newNode->next = *header;
    *header = newNode;
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
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
            }

            break;
        case 2:
            printf("1.\tFrom Front\n2.\tFrom End\n3.\tFrom a Position\n");
            printf("Enter your choice: ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                printf("Invalid Choice\n");
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