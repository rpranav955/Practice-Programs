// Program to find nth fibonacci number.
#include <stdio.h>
int fibo(int n){
	if (n==0) return 0;
	else if (n==1) return 1;
	else return fibo(n-1) + fibo(n-2); //Recursion
}
int main(){
	int n;
	printf("Enter the position of the fibo number to be found:\n");
	scanf("%d",&n);
	printf("%dth fibo number is %d\n", n, fibo(n-1));
return 0;
}
