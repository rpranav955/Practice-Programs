#include <stdio.h>
int main()
{int num,num0,sum=0,digit,fact=1;
	printf("Enter your number:\n");
	scanf("%d",&num);
	num0=num;
	
	while(num!=0)
	{
		digit=num%10;
		while(digit!=0)
		{
			fact*=digit;
			digit-=1;
		}
		digit=0;
		sum+=fact;
		fact=1;
		num/=10;
	}
	if(sum==num0)
	{
		printf("%d is a Krishnamurthy number.\n",num0);
	}
	else
	{
		printf("%d is not a Krishnamurthy number.\n",num0);
	}
return 0;
}
			
		
