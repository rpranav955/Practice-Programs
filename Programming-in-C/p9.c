#include <stdio.h>
int main()
{int num,num0,sum=0;
	printf("Enter your number:\n");
	scanf("%d",&num);
	
	for(int i=1;i<num;i++)
	{
		if(num%i==0)
		{
			sum+=i;
		}
	}
	if(sum==num)
	{
		printf("%d is a Perfect number\n",num);
	}
	else
	{
		printf("%d is not a Perfect number\n",num);
	}
return 0;
}
