#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10

int front = -1, rear = -1;

void frontEnqueue(int queue[], int item){
    if(front == -1 && rear == -1){
        rear =0;
        queue[++front] = item;
        printf("%d queued at the front\n", item);
    } else if(rear == (front-1)%MAXSIZE){
        printf("Queue Overflow\n");
    } else {
        front = (front-1)%MAXSIZE;
        queue[front]=item;
        printf("%d queued at the front\n", item);
    }
}

void rearEnqueue(int queue[], int item){
    if(front == -1 && rear == -1){
        front =0;
        queue[++rear] = item;
        printf("%d queued at the rear\n", item);
    } else if(front == (rear+1)%MAXSIZE){
        printf("Queue Overflow\n");
    } else {
        rear = (rear+1)%MAXSIZE;
        queue[rear]=item;
        printf("%d queued at the rear\n", item);
    }
}

int rearDequeue(int queue[]){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
        return 0;
    } else {
        int item = queue[rear];
        if(queue[rear] == queue[front]){
            front = -1; rear = -1;
            return item;
        }
        else{
            rear = (rear-1)%MAXSIZE;
            return item;
        }
        
    }
}

int frontDequeue(int queue[]){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
        return 0;
    } else {
        int item = queue[front];
        if(queue[rear] == queue[front]){
            queue[front]=0;
            front = -1; rear = -1;
            return item;
        }
        else{
            queue[front] = 0;
            front = (front+1)%MAXSIZE;
            return item;
        }
        
    }
}

void printArray(int a[], int front, int rear){
    for(int i =front; i!=rear; i = (i+1)%MAXSIZE){
        printf("%d ", a[i]);
    }
    printf("%d ",a[rear]);
    printf("\n");
}

int main(){
    
    int queue[MAXSIZE];
    int choice;
    
    printf("1. Input Restricted Deque\n2. Output Restricted Deque\n3. No Restriction\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);
    bool isEnd = false;
    
    switch(choice){
        case 1:
        while(!isEnd){
        printf("Enter your choice:\n");
        printf("1. Input into rear\n2. Output from front\n3. Output from rear\n4. Print Queue\n5. Exit\n");
        int choice1; 
        scanf("%d",&choice1);
        printf("\n");
        switch(choice1){
            case 1: printf("Enter your element: ");
                    int item;
                    scanf("%d", &item);
                    rearEnqueue(queue, item);
                    break;
            
            case 2: int n1 = frontDequeue(queue);
                    if(n1 != 0){
                        printf("%d dequeued\n",n1);
                    }
                    break;
                    
            case 3: int n2 = rearDequeue(queue);
                    if(n2 != 0){
                        printf("%d dequeued\n",n2);
                    }
                    break;

            case 4: printArray(queue, front ,rear );
                    printf("\n");
                    break;

            case 5: isEnd = true;
                    break;
            
            default: printf("Invalid Choice\n");
        }
    }
                break;
                
        case 2:
        while(!isEnd){
        printf("Enter your choice:\n");
        printf("1. Input into front\n2. Input into rear\n3. Output from front\n4. Print Queue\n5. Exit\n");
        int choice1; 
        scanf("%d",&choice1);
        printf("\n");
        switch(choice1){
            case 1: printf("Enter your element: ");
                    int item2;
                    scanf("%d", &item2);
                    frontEnqueue(queue, item2);
                    break;
            
            case 2: printf("Enter your element: ");
                    int item3;
                    scanf("%d", &item3);
                    rearEnqueue(queue, item3);
                    break;
                    
            case 3: int n3 = frontDequeue(queue);
                    if(n3 != 0){
                        printf("%d dequeued\n",n3);
                    }
                    break;

            case 4: printArray(queue, front ,rear );
                    printf("\n");
                    break;

            case 5: isEnd = true;
                    break;
            
            default: printf("Invalid Choice\n");
        }
    }
                break;
                
        case 3:
        while(!isEnd){
        printf("Enter your choice:\n");
        printf("1. Input into front\n2. Input into rear\n3. Output from front\n4. Output from rear\n5. Print Queue\n6. Exit\n");
        int choice1; 
        scanf("%d",&choice1);
        printf("\n");
        switch(choice1){
            case 1: printf("Enter your element: ");
                    int item4;
                    scanf("%d", &item4);
                    frontEnqueue(queue, item4);
                    break;
            
            case 2: printf("Enter your element: ");
                    int item5;
                    scanf("%d", &item5);
                    rearEnqueue(queue, item5);
                    break;
                    
            case 3: int n4 = frontDequeue(queue);
                    if(n4 != 0){
                        printf("%d dequeued\n",n4);
                    }
                    break;
                    
            case 4: int n5 = rearDequeue(queue);
                    if(n5 != 0){
                        printf("%d dequeued\n",n5);
                    }
                    break;

            case 5: printArray(queue, front ,rear );
                    printf("\n");
                    break;

            case 6: isEnd = true;
                    break;
            
            default: printf("Invalid Choice\n");
        }
    }
                break;
        default: printf("Invalid Choice");
    }
    
    return 0;
}
