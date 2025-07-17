#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 10
int top = -1;

void push(char stack[], char item)
{
    if (top == MAXSIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = item;
        // printf("%c pushed into the stack\n", item);
    }
}

char pop(char stack[])
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        // printf("%c popped\n", stack[top]);
        return stack[top--];
    }
}

char peek(char stack[])
{
    if (top < 0)
    {
        printf("Empty Stack\n");
        return '\0';
    }
    else
    {
        return stack[top];
    }
}

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')' ||
        open == '{' && close == '}' ||
        open == '[' && close == ']')
        return true;
    else
        return false;
}

int main()
{

    char stack[MAXSIZE];
    char input[MAXSIZE];
    printf("Enter your paranthesis: ");
    fgets(input, MAXSIZE, stdin);
    int flag = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        char ch = input[i];
        if (ch == '[' || ch == '{' || ch == '(')
            push(stack, ch);
        else if (ch == ']' || ch == '}' || ch == ')')
            if (top == -1)
            {
                printf("Invalid Sequence\n");
                return 0;
            }
            else if (!isMatching(pop(stack), ch))
            {
                printf("Invalid Sequence\n");
                return 0;
            }
            else
                continue;
    }
    if (top == -1)
    {
        printf("Valid Sequence\n");
    }
    else
    {
        printf("Invalid Sequence\n");
    }

    return 0;
}
