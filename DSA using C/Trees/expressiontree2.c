/*
    directly uses the infix equation
    to create the expression tree
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char ch;
    struct node *left, *right;
} Node;

Node *root = NULL;

Node *createNode(char ch)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        exit(1);
    }

    newNode->ch = ch;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }

    return 0;
}

void createExpressionTree(char infix[])
{

    int i = 0;
    char opStack[50];
    Node *nodeStack[50];
    int nodeStackTop = -1;
    int opStackTop = -1;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            nodeStack[++nodeStackTop] = createNode(ch);
        }
        else if (ch == '(')
        {
            opStack[++opStackTop] = ch;
        }
        else if (ch == ')')
        {
            while (opStack[opStackTop] != '(')
            {
                Node *newNode = createNode(opStack[opStackTop--]);

                newNode->right = nodeStack[nodeStackTop--];
                newNode->left = nodeStack[nodeStackTop--];

                nodeStack[++nodeStackTop] = newNode;
            }
            opStackTop--;
        }
        else
        {
            while (opStackTop > -1 && precedence(ch) <= precedence(opStack[opStackTop]))
            {
                Node *newNode = createNode(opStack[opStackTop--]);

                newNode->right = nodeStack[nodeStackTop--];
                newNode->left = nodeStack[nodeStackTop--];

                nodeStack[++nodeStackTop] = newNode;
            }

            opStack[++opStackTop] = ch;
        }

        i++;
    }

    while (opStackTop != -1)
    {
        Node *newNode = createNode(opStack[opStackTop--]);

        newNode->right = nodeStack[nodeStackTop--];
        newNode->left = nodeStack[nodeStackTop--];
        nodeStack[++nodeStackTop] = newNode;
    }

    root = nodeStack[nodeStackTop--];
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    printf("%c", root->ch);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }

    printf("%c", root->ch);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%c", root->ch);
}

int main()
{
    char infix[50];

    printf("Enter your infix expression: ");
    scanf("%s", infix);
    createExpressionTree(infix);

    int isEnd = 0;

    while (!isEnd)
    {
        int choice;

        printf("\nPrint the Expression Tree:\n");
        printf("\n1. InOrder\n2. PreOrder\n3. PostOrder\n\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nInorder: ");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("\nPreorder: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("\nPostorder: ");
            postorder(root);
            printf("\n");
            break;
        case 0:
            isEnd = 1;
            break;
        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}
