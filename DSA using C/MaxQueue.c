// Program to find max element in a queue.

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
int front = -1, rear = -1;

void Enqueue(int queue[], int item){
    if (front == -1 && rear == -1){
        front = 0;
        queue[++rear] = item;
    } else if (front == (rear + 1)%MAXSIZE){
        printf("Queue Overflow\n\n");
    } else {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = item;
    }
}

int Dequeue(int queue[]){
    if (front == -1 && rear == -1){
        printf("Queue Underflow\n\n");
        return 0;
    } else if (front == rear){
        int item = queue[front];
        front = -1; rear = -1;
        return item;
    } else {
        int item = queue[front];
        front = (front + 1) % MAXSIZE;
        return item;
    }
}

void printQueue(int queue[]){
    for(int i = front; i != rear; i = (i + 1)%MAXSIZE){
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[rear]);
    printf("\n\n");
}

int findMax(int queue[]){
    int item = 0;
    int length = (rear - front + MAXSIZE) % MAXSIZE;
    for(int i = 0; i <= length; i++){
        int dequeued = Dequeue(queue);
        if(dequeued > item){
            item = dequeued;
        }
        Enqueue(queue, dequeued);
    }
    return item;
}


int main(){

    int queue[MAXSIZE];
    bool isEnd = false;
    while(!isEnd){
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Max Element\n5. Stop\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("\nEnter your element: ");
                    int n1;
                    scanf("%d", &n1);
                    Enqueue(queue, n1);
                    printf("%d added to the queue\n\n", n1);
                    break;
            
            case 2: int n2 = Dequeue(queue);
                    if(n2 != 0){
                        printf("%d removed from the queue\n\n", n2);
                    }
                    break;
            
            case 3: printQueue(queue);
                    break;

            case 4: printf("%d is the Max element in the queue\n\n", findMax(queue));
                    break;
            
            case 5: isEnd = true;
                    break;
            
            default: printf("Invalid choice\n\n");
        }
    }


    return 0;
}
