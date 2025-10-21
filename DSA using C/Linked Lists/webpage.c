#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *curr = NULL;

char *page(int num)
{
	switch (num)
	{
	case 1:
		return "Home";
	case 2:
		return "About";
	case 3:
		return "Contact";
	default:
		return "";
	}
}

void printHistory()
{
	if (!head)
	{
		printf("No Page Visited\n");
		return;
	}

	Node *ptr = head;
	do
	{
		printf("%s", page(ptr->data));
		if (ptr->next)
		{
			printf(" -> ");
			ptr = ptr->next;
		}
		else
		{
			break;
		}

	} while (true);
	printf("\n");
}

void addPage(int num)
{
	if (curr)
	{
		if (curr->data == num)
		{
			printf("Currenty in that page!\n\n");
			return;
		}
	}

	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode)
	{
		printf("Memory Allocation Failed!\n");
		return;
	}

	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (!head)
	{
		head = newNode;
		tail = newNode;
		curr = newNode;

		printf("Current Page: %s\n\n", page(curr->data));
		printHistory();

		return;
	}

	curr->next = newNode;
	newNode->prev = curr;
	tail = newNode;
	curr = newNode;

	printf("Current Page: %s\n\n", page(curr->data));
	printHistory();
}

int main()
{
	bool isEnd = false;
	int choice;

	while (!isEnd)
	{
		printf("\n1. Home\n2. About\n3. Contact\n4. Previous Page\n5. Forward Page\n6. Print History\n7. Stop\n\nEnter: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			addPage(1);
			break;
		case 2:
			addPage(2);
			break;
		case 3:
			addPage(3);
			break;
		case 4:
			if (!tail)
			{
				printf("No Pages visited\n");
				break;
			}
			if (!curr->prev)
			{
				printf("Theres no Previous Page\n");
				break;
			}
			curr = curr->prev;
			printf("Current Page: %s\n\n", page(curr->data));
			printHistory();
			break;
		case 5:
			if (!head)
			{
				printf("No Pages visited\n");
				break;
			}
			if (!curr->next)
			{
				printf("Theres no Forward Page\n");
				break;
			}
			curr = curr->next;
			printf("Current Page: %s\n\n", page(curr->data));
			printHistory();
			break;
		case 6:
			printHistory();
			break;
		case 7:
			isEnd = true;
			break;
		default:
			printf("Invalid Choice\n");
		}
	}

	return 0;
}
