#include <stdio.h>

int main(){
	
	int i,fibo[20];
	
	fibo[0] = 0;
	fibo[1] = 1;
	
	for(i=2;i<=20;i++){
		fibo[i] = fibo[i-2] + fibo[i-1];
	}
	printf("The elements of fibo array \n");
	
	for(i=0;i<=20;i++){
		printf("fibo[%d] = %d\n",i,fibo[i]);
	}
	return 0;
}
