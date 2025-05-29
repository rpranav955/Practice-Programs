#include <stdio.h>

int main()
{
	int n, i;

	printf("Enter your number of elements needed to be added in the array: \n");
	scanf("%d", &n);

	int arr[n];

	printf("Enter the elements for the array: \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d\n", &arr[i]);
	}

	int large;

	large = arr[0];

	for (i = 0; i < n; i++)
	{
		if (arr[i] > large)
			large = arr[i];
	}

	printf("The largest element: %d\n", large);

	return 0;
}
