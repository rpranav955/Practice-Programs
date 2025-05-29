#include <stdio.h>

int main(){
	
	int n, i, j, temp;
	
	//Get the number of elements to be used from the user.
	printf("Enter the number of elements in an array: \n");
	scanf("%d", &n);
	
	//Declare the array.
	int a[n];
	
	//Input the elements into the array.
	printf("Enter the elements: \n");
	for (i= 0; i< n; i++){
		scanf("%d", &a[i]);
	}
	
	//Bubble Sort.
	
	//Starting the loop for each iterations of Bubble Sort.
	for (i = 0; i < n-1; i++) {
		//Loop for comparing two elements.
		for (j = 0; j <= n-i-1; j++) { 
			if(a[j] > a[j+1]) {
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	
	//Print the sorted array.
	printf("Sorted array: \n");
	for (i=0; i<n; i++){
		printf("%d\n", a[i]);
	}
return 0;
}
