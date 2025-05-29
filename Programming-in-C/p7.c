#include <stdio.h>
int main()
{int n,sumeven=0,sumodd=0;
	printf("Enter the number of numbers you want to enter:\n");
	scanf("%d",&n);
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		printf("Enter your number:\n");
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
			{sumeven+=a[i];}
		else
			{sumodd+=a[i];}
	}
	printf("Sum of Odd numbers:%d\nSum of Even numbers:%d\n",sumodd,sumeven);
return 0;
}
