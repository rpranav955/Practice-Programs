#include <stdio.h>
int main()
{int num,sum;
	printf("Enter your number:\n");
	scanf("%d",&num);
	
	sum=num%10;
	
	while(num>=10)
	{
		num/=10;
	}
	sum+=num;
	printf("Sum of First and Last digits of a number is : %d\n",sum);
return 0;
}
