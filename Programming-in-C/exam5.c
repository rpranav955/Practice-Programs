// Program to print fibonacci series using recursive function.
#include <stdio.h>

// Declaring and defining the function.
int fibo(int n){
	if (n==0) return 0;
	else if (n==1) return 1;
	else return fibo(n-1)+fibo(n-2);
}

// Main function body.
int main(){

	// Getting input from the user.
	int num;
	printf("Enter the number of terms: \n");
	scanf("%d", &num);

	// Calling the function.
	for(int i=0; i<num; i++) {printf("%d  ", fibo(i));}
	printf("\n");

return 0;
}
