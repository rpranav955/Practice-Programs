#include <stdio.h>

int main() {
	
	int a[3][3], i, j;
	
	// Inputing elements into the 2d array
	
	printf("Enter the elements:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	// Printing the matrix
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

