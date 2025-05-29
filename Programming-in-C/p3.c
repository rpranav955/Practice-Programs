#include <stdio.h>
int main()
{int num,num0,sq,digit,sum=0;
	printf("Enter your number:\n");
	scanf("%d",&num);
	num0=num;
	sq=num*num;
	while(sq!=0)
	{
		digit=sq%10;
		sum+=digit;
		sq/=10;
	}
	if(sum==num0)
	{
		printf("%d is a Neon Number\n",num0);
	}
	else
	{
		printf("%d is not a Neon Number\n",num0);
	}
return 0;
}
	
