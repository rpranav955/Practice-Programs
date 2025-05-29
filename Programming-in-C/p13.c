//Krishnamurthy number in range

#include <stdio.h>
int main()
{int start,end,sum=0,digit,temp;
	printf("Enter your starting limit:\n");
	scanf("%d",&start);
	printf("Enter your ending limit:\n");
	scanf("%d",&end);
	
	while(start<=end)
	{
		temp=start;
		while(temp>0)
		{
			digit=temp%10;
			int fact=1;
			while(digit>0)
			{
				fact*=digit;
				digit-=1;
			}
			sum+=fact;
			temp/=10;
		}
		if(sum==start){printf("%d is a krishnamurthy number\n",sum);}
		sum=0;
		start+=1;
	}
return 0;
}