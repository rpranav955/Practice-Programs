// Program to find the sum of elements of an array using recursive function.
#include <stdio.h>

int SUM(int arr[], int l){
	if (l==0) return 0;
	else return arr[l-1] + SUM(arr, l-1);
}

int main(){
	int num;
	printf("Enter num:\n");
	scanf("%d", &num);
	int a[num];
	printf("Enter your elements:\n");
	for(int i=0; i< num; i++){
		scanf("%d", &a[i]);}
	
	printf("Sum of elements = %d\n", SUM(a, num));
return 0;
}
