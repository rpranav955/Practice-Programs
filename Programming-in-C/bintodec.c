#include <stdio.h>
int main(){
    int num, count=0;
    printf("Enter your number:\n");
    scanf("%d", &num);
    int temp=num;
    while(temp>0){
        if(temp%2==0) count++;
        else count++;
        temp/=2;
    }
    int arr[count];
    int count2;
    while(count2!=count){
        if(num%2==0) {arr[count2]=0;count2++;}
        else {arr[count2]=1;count2++;}
        num/=2;
    }
    for(int i=count-1; i>=0; i--){
        printf("%d", arr[i]);
    }
    
return 0;
}
