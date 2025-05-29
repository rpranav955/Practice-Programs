#include <stdio.h>
int main()
{
	for(int i=5;i<=15;i++)
	{
		printf("Multiplication Table of %d\n",i);
		
		for(int j=1;j<=10;j++)
		{
			int z=i*j;
			printf("%d x %d = %d\n",j,i,z);
		}
	}
return 0;
}
			
			
