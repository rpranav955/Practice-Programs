#include <stdio.h>
int main()
{int num,num0,sum=0;
	printf("Enter the number of odd integers to be found sum of:\n");
	scanf("%d",&num);
	num0=num*2;
	for(int i=1;i<=num0;i++)
	{
		
		if(i%2!=0)
		{
			sum+=i;
		}
		
	}
	printf("Sum of the first %d odd is %d\n",num,sum);
return 0;
}
