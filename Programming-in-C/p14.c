//Armstrong number in range

#include <stdio.h>
int main()
{int start,end,digitcount;
	printf("Enter your starting limit:\n");
	scanf("%d",&start);
	printf("Enter your ending limit:\n");
	scanf("%d",&end);

	for(int i=start;i<=end;i++){
			int temp1=i;
			digitcount=0;
			while(temp1>0){
				temp1/=10;
				digitcount++;
			}
			int sum=0;
			int temp2=i;
			while(temp2>0){
					int digit;
					digit=temp2%10;
					temp2/=10;
					int pwr=1;
						for(int i=0;i<digitcount;i++){
							pwr*=digit;
						}
					sum+=pwr;
			}
			if(sum==i){printf("%d\n",sum);}
	}
return 0;
}
