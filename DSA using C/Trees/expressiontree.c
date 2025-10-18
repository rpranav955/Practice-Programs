/*
    i first converted infix equation
    to postfix and then creates the bst
    using the postfix equation
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

typedef struct node
{
    char data;
    struct node *left, *right;
} Node;

int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

char *postfixConversion(char infix[])
{
    char *postfix = (char *)malloc(MAX * sizeof(char));
    if (!postfix)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    int index = -1;
    char stack[MAX];
    int top = -1;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            postfix[++index] = ch;
        }
        else if (isspace(ch))
        {
            continue;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[++index] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top != -1 && precedence(ch) <= precedence(stack[top]))
            {
                postfix[++index] = stack[top--];
            }
            stack[++top] = ch;
        }
    }
    while (top != -1)
    {
        postfix[++index] = stack[top--];
    }
    postfix[++index] = '\0';
    return postfix;
}

void bst(char postfix[], Node **root)
{
    Node *stack[MAX];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = postfix[i];
        if (isalnum(postfix[i]))
        {
            newNode->left = newNode->right = NULL;
            stack[++top] = newNode;
        }
        else
        {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
        *root = stack[top];
    }
}

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

int main()
{

    Node *root = NULL;

    printf("Enter infix expression: ");
    char infix[MAX];
    fgets(infix, MAX, stdin);

    char postfix[MAX];
    strcpy(postfix, postfixConversion(infix));
    bst(postfix, &root);

    printf("\nPreorder: ");
    preorder(root);
    printf("\n");
    printf("\nInorder: ");
    inorder(root);
    printf("\n");
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    return 0;
}