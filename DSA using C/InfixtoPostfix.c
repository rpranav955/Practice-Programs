#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int top = -1;
int maxSize = 50;

void push(char stack[], char item)
{
    if (top == (maxSize - 1))
    {
        //printf("Stack Overflow\n");
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
        //printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char item = stack[top--];
        stack[top + 1] = 0;
        return item;
    }
}

char peek(char stack[])
{
    if (top < 0)
    {
        //printf("Stack Empty\n");
        return 0;
    }
    else
    {
        return stack[top];
    }
}

/*void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}*/

int precedence(char c){
	if(c=='^') {return 3;}
	else if(c=='*' || c=='/') {return 2;}
	else if(c=='+' || c=='-') {return 1;}
	else {return 0;}
}

char* convert(char infix[]){
	
	char* postfix = (char*)malloc(maxSize * sizeof(char));
	if(postfix == NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	
	char stack[maxSize];
	int num = 0;
	
	for(int i = 0; infix[i] != '\0'; i++){
		if(isalnum(infix[i])){
			postfix[num++] = infix[i];
		}
		else if(infix[i] == '('){
			push(stack, infix[i]);
		}
		else if(infix[i] == ')'){
			while(peek(stack) != '('){
				postfix[num++] = pop(stack);
			}
			pop(stack);
		}
		else{
			while( top != -1 && precedence(infix[i]) <= precedence(peek(stack))){
				postfix[num++] = pop(stack);
			}
			push(stack, infix[i]);
		}
	}
	while(top != -1){
			postfix[num++] = pop(stack);
	}
	
	postfix[num]= '\0';
	
	return postfix;
	
}

int main()
{
    
    printf("Enter your equation: ");
    char infix[maxSize];
    //fgets(infix, maxSize, stdin);
    scanf("%s", infix);
    
    char* postfix = convert(infix);
	 printf("Postfix: %s\n", postfix);
    
    free(postfix);
    
    
    return 0;
}
