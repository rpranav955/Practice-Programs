// Program to find Factorial of a number using recursive function.
#include <stdio.h>

//Function Declaration and Definition.
int fact(int n){
	if (n==0) return 1;
	else if (n==1) return 1;
	else {while(n>0){return n*fact(n-1);}};
}

//Main function
int main(){
	int num;
	// Getting user input.
	printf("Enter your number:\n");
	scanf("%d", &num);
	
	//Function Calling and printing.
	printf("%d! = %d\n", num, fact(num));
	
return 0;
}
	
