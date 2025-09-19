#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[500];
    struct node *next;
    struct node *prev;
} Node;

int main(){
	
	Node page1, page2, page3;
	bool isEnd = false;
	char choice;
	
	strcpy(page1.data, "\nPage1\n");
	page1.next = &page2;
	page1.prev = NULL;
	
	strcpy(page2.data, "\nPage2\n");
	page2.next = &page3;
	page2.prev = &page1;
	
	strcpy(page3.data, "\nPage3\n");
	page3.next = NULL;
	page3.prev = &page2;
	
	Node *ptr = &page1;
	
	printf("%s", ptr->data);
	
			
	printf("\npress f for forward\npress b for backward\npress e to exit\n");
	
	while(!isEnd){
	
		scanf("%c", &choice);
		
		switch(choice){
			
			case 'f':	
				if(!ptr->next){
					printf("Theres no page ahead\n");
					break;
				}
				ptr = ptr->next;
				printf("%s", ptr->data);
				break;
				
			case 'b':	
				if(!ptr->prev){
					printf("Theres no page behind\n");
					break;
				}
				ptr = ptr->prev;
				printf("%s", ptr->data);
				break;
			
			case 'e':	
				isEnd = true;
				break;
	}
 }
	return 0;
}
