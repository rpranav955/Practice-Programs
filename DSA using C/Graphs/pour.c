#include <stdio.h>
#include <stdlib.h>

#define INF 999
#define MAX_CAPACITY 11
#define MAX_A 10
#define MAX_B 7
#define MAX_C 4

typedef struct node
{
    int a, b, c;
    struct node *parent;
} Node;

typedef struct queuenode
{
    Node *node;
    struct queuenode *next;
} QueueNode;

QueueNode *head = NULL, *tail = NULL;

Node *createState(int a, int b, int c, Node *parent)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->a = a;
    newNode->b = b;
    newNode->c = c;
    newNode->parent = parent;

    return newNode;
}

void enqueueNode(Node *item)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->node = item;
    newNode->next = NULL;

    if (!head)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

    return;
}

Node *dequeueNode()
{

    if (!head)
    {
        return NULL;
    }

    if (head == tail)
    {
        QueueNode *item = head;
        head = tail = NULL;

        return item->node;
    }

    QueueNode *item = head;
    head = head->next;

    return item->node;
}

void printPath(Node *curr)
{
    if (!curr)
    {
        return;
    }
    printPath(curr->parent);
    printf("(%d, %d, %d)\n", curr->a, curr->b, curr->c);
}

int visitedStates[MAX_CAPACITY][MAX_CAPACITY][MAX_CAPACITY] = {0};

int main()
{
    enqueueNode(createState(0, 7, 4, NULL));
    while (head)
    {
        Node *curr = dequeueNode();

        int currA = curr->a;
        int currB = curr->b;
        int currC = curr->c;

        int pouramt, newA, newB, newC;

        if (currB == 2 || currC == 2)
        {
            printf("Solution Path Found:\n");
            printPath(curr);
            return 0;
        }

        // A -> B
        pouramt = (currA + currB > MAX_B) ? MAX_B - currB : currA;
        newA = currA - pouramt, newB = currB + pouramt, newC = currC;
        if (visitedStates[newA][newB][newC] != 1)
        {
            visitedStates[newA][newB][newC] = 1;
            enqueueNode(createState(newA, newB, newC, curr));
        }

        // A -> C
        pouramt = (currA + currC > MAX_C) ? MAX_C - currC : currA;
        newA = currA - pouramt, newB = currB, newC = currC + pouramt;
        if (visitedStates[newA][newB][newC] != 1)
        {
            visitedStates[newA][newB][newC] = 1;
            enqueueNode(createState(newA, newB, newC, curr));
        }

        // B -> A
        pouramt = (currB + currA > MAX_A) ? MAX_A - currA : currB;
        newA = currA + pouramt, newB = currB - pouramt, newC = currC;
        if (visitedStates[newA][newB][newC] != 1)
        {
            visitedStates[newA][newB][newC] = 1;
            enqueueNode(createState(newA, newB, newC, curr));
        }

        // B -> C
        pouramt = (currB + currC > MAX_C) ? MAX_C - currC : currB;
        newA = currA, newB = currB - pouramt, newC = currC + pouramt;
        if (visitedStates[newA][newB][newC] != 1)
        {
            visitedStates[newA][newB][newC] = 1;
            enqueueNode(createState(newA, newB, newC, curr));
        }

        // C -> A
        pouramt = (currA + currC > MAX_A) ? MAX_A - currA : currC;
        newA = currA + pouramt, newB = currB, newC = currC - pouramt;
        if (visitedStates[newA][newB][newC] != 1)
        {
            visitedStates[newA][newB][newC] = 1;
            enqueueNode(createState(newA, newB, newC, curr));
        }

        // C -> B
        pouramt = (currB + currC > MAX_B) ? MAX_B - currB : currC;
        newA = currA, newB = currB + pouramt, newC = currC - pouramt;
        if (visitedStates[newA][newB][newC] != 1)
        {
            visitedStates[newA][newB][newC] = 1;
            enqueueNode(createState(newA, newB, newC, curr));
        }
    }

    printf("No Solution Path found\n");
    return 0;
}
