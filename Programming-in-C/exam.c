#include <stdio.h>

int gcd(int a, int b){
		if(b!=0) {return gcd(b, a % b);}
		else {return a;}
	}
void main(){	
	int n1, n2;
	printf("Enter two numbers:\n");
	scanf("%d %d", &n1, &n2);
	printf("Greatest common divisor of %d and %d is %d\n", n1, n2, gcd(n1,n2));
}
