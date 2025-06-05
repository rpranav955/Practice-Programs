// Structure of Hotels according to their name rating and other stuffs like price
#include <stdio.h>
#include <string.h>

struct Hotel{
    char name[25];
    char address[100];
    char grade;
    int roomchg;
    int roomnum;
}h[5], temp;

void find(struct Hotel h[], char grade){
    int flag=0;
    for(int i=0; i<5; i++){
        
        if(h[i].grade==grade){
            printf("%s\t%s\t%c\t%d\t%d\n", h[i].name, h[i].address, h[i].grade, h[i].roomchg, h[i].roomnum);
            flag++;
        }
    }
    if ( flag == 0){
        printf("No Hotels found with your preferred Grade.\n");
    }
    
}

void main(){
    h[0]=(struct Hotel){"ONE","Kochi,India", 'A', 15000, 50};
    h[1]=(struct Hotel){"TWO","Chennai,India", 'B', 13500, 20};
    h[2]=(struct Hotel){"THREE","Banglore,India", 'B', 17500, 30};
    h[3]=(struct Hotel){"FOUR","Kolkata,India", 'B', 15500, 40};
    h[4]=(struct Hotel){"FIVE","Goa,India", 'A', 12500, 10};
    //Bubble sorting hotels according to their price.
    for(int i=0; i<5-1; i++){
        for(int j=0; j<5-i-1; j++){
            if(h[j].roomchg > h[j+1].roomchg){
                temp=h[j];
                h[j]=h[j+1];
                h[j+1]=temp;
            }
        }
    }
    char g;
    printf("Enter your preferred Grade\n");
    scanf("%c",&g);
    
    find(h, g);
    
    
}
