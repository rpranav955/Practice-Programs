#include <stdio.h>
int main()
{int a[3],great,count=0;
	for(int i=0;i<3;i++)
	{
		printf("Enter your number:\n");
		scanf("%d",&a[i]);
	}
	if(a[0]>a[1] && a[0]>a[2])
	{	
		great=a[0];
		printf("%d is the greatest number\n",great);
	}
	else if(a[1]>a[0] && a[1]>a[2])
	{	
		great=a[1];
		printf("%d is the greatest number\n",great);
	}
	else
	{	
		great=a[2];
		printf("%d is the greatest number\n",great);
	}
	for(int i=1;i<=great;i++)
	{
		if(great%i==0)
			{count++;}
	}
	if(count==2)
		{printf("%d is a Prime Number also\n",great);}
	else
		{printf("%d is a not Prime Number\n",great);}
return 0;
}
