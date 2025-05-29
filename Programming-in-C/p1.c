#include <stdio.h>
int main()
{
	int count;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			printf("%d\t", i);
		}
		count = 0;
	}
	return 0;
}
