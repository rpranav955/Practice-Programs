#include <stdio.h>
int main()
{int num,count;
	printf("Enter your number:\n");
	scanf("%d",&num);
	
	while(num!=0)
	{
		num/=10;
		count++;
	}
	printf("%d is the number of digits\n",count);
return 0;
}
	
