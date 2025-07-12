#include <stdio.h>
#define MAXSIZE 10

int top = -1;

void push(char stack[], char item)
{
    if (top == (MAXSIZE - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = item;
    }
}

char pop(char stack[])
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return 'Z';
    }
    else
    {
        char item = stack[top--];
        stack[top + 1] = 0;
        return item;
    }
}
int main()
{
    char item[] = "         ";
    char stack[] = "         ";

    printf("Enter your String: ");
    fgets(item, MAXSIZE, stdin);

    for (int i = 0; i < MAXSIZE; i++)
    {
        push(stack, item[i]);
    }
    for (int i = 0; i < MAXSIZE; i++)
    {
        char popped = pop(stack);
        if (popped != 'Z')
        {
            printf("%c", popped);
        }
    }
    printf("\n");

    return 0;
}
