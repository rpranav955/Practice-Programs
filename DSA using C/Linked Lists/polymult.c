#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int coeff;
    int exp;
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
        		if(ptr->exp == 1){
        			printf("%d x", ptr->coeff);
        		}
        		else if(ptr->exp == 0){
        			printf("%d", ptr->coeff);
        		}
            else{
            printf("%d x^%d", ptr->coeff, ptr->exp);
            }
            
            if(ptr->next){
            	printf(" + ");
            }
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void addNodeAtEnd(Node **headAddress)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation failed\n");
        return;
    }
    printf("Enter the coefficient: ");
    scanf("%d", &newNode->coeff);
    printf("Enter the exponent: ");
    scanf("%d", &newNode->exp);
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

void connect(Node **multi, Node *newNode){
	if(!*multi){
		*multi = newNode;
		return; 
	}
	
    Node *ptr = *multi;
	
   while (ptr->next)
   {
       ptr = ptr->next;
   }
   ptr->next = newNode;
	
}

void multiplication(Node *header1, Node *header2, Node **multi){
	
	Node *ptr1 = header1, *ptr2 = header2, *prev = NULL;
	
	while(ptr1){
		while(ptr2){
		
			Node *newNode = (Node *)malloc(sizeof(Node));
			newNode->next = prev;
  			if (!newNode)
    		{
    	    printf("Memory Allocation failed\n");
    	    return;
   	 	}
   	 	
			newNode->coeff = ptr1->coeff * ptr2->coeff;
			newNode->exp = ptr1->exp * ptr2->exp;
			
			connect(multi, newNode);
			
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	
}

int main(){
	
	Node *header1 = NULL, *header2 = NULL, *multi = NULL;
	int n1, n2;
	
	printf("Enter the number of non-zero elements of Polynomial 1: ");
	scanf("%d", &n1);
	
	printf("Enter the number of non-zero elements of Polynomial 2: ");
	scanf("%d", &n2);
	
	printf("\nEnter your Polynomial 1:\n");
	for(int i = 0; i < n1; i++){
		
		
		addNodeAtEnd(&header1);
		
	}
	
	printf("\nEnter your Polynomial 2:\n");
	for(int i = 0; i < n2; i++){
	

		addNodeAtEnd(&header2);
		
	}
	
	printf("\nYour Polynomial 1: "); 
	printSLL(header1);
	
	printf("\nYour Polynomial 2: "); 
	printSLL(header2);
	
	multiplication(header1, header2, &multi);
	
	printf("\nPoly1 x Poly2: "); 
	printSLL(multi);
	
	return 0;
}
