#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10

int front = -1, rear = -1;

void Enqueue(int queue[], int item){
    if(front == -1 && rear == -1){
        front =0;
        queue[++rear] = item;
        printf("%d queued\n", item);
    } else if(rear == MAXSIZE -1){
        printf("Queue Overflow\n");
    } else {
        queue[++rear]=item;
        printf("%d queued\n", item);
    }
}

int Dequeue(int queue[]){
    if(front == -1 && rear == -1 || front > rear){
        printf("Queue Underflow\n");
        return 0;
    } else {
        int item = queue[front];
        queue[front++]=0;
        return item;
    }
}

void printArray(int a[], int front, int rear){
    for(int i =front; i<rear+1; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    
    int queue[MAXSIZE];
    
    bool isEnd = false;

    while(!isEnd){
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\n\n");
        int choice; 
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1: printf("Enter your element: ");
                    int item;
                    scanf("%d", &item);
                    Enqueue(queue, item);
                    break;
            
            case 2: int n = Dequeue(queue);
                    if(n != 0){
                        printf("%d dequeued\n",n);
                    }
                    break;

            case 3: printArray(queue, front, rear);
                    printf("\n");
                    break;

            case 4: isEnd = true;
                    break;
            
            default: printf("Invalid Choice\n");
        }
    }

    return 0;
}
