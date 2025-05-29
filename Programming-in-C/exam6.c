// Program to find sum of digits of a number using recursive funciton.
#include <stdio.h>

//Declaring and defining the function.
int sumdig(int n){
	if (n==0) return 0;
	else return (n%10) + sumdig(n/10);
}

// Main body function.
int main(){
	int num;
	
	// Getting user input.
	printf("Enter your number:\n");
	scanf("%d", &num);
	
	// Calling the function and printing the result.
	printf("%d => %d\n", num, sumdig(num));

return 0;
}
