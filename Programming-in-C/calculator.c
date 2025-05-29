#include <stdio.h>
int main(){
	int a,b,c;
	char p;
	printf("Choose the symbol below:\nAddition:+\nSubtraction:-\nMultiplication:*\nDivision:/\n");
	scanf("%c",&p);
	printf("Enter your first number:\n");
	scanf("%d",&a);
	printf("Enter your second number:\n");
	scanf("%d",&b);
	
	switch(p)
	{
	case '+': c=a+b;
		printf("%d + %d = %d\n",a,b,c);
	break;
	case '-': c=a-b;
		printf("%d - %d = %d\n",a,b,c);
	break;
	case '*': c=a*b;
		printf("%d * %d = %d\n",a,b,c);
	break;
	case '/': c=a/b;
		printf("%d / %d = %d\n",a,b,c);
	break;
	default: printf("Enter a valid input\n");
	}
return 0;
}
