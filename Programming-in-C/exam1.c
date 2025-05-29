//Pass an array into a function, then find its largest smallest then sum and average of that array.
#include <stdio.h>
void largesmall(int a[], int l){
	int g=a[0],s=a[0];
	for(int i=0; i<l; i++){ if(a[i]>g) {g=a[i];}}
	for(int i=0; i<l; i++){ if(a[i]<s) {s=a[i];}}
	
	printf("Largest element: %d\n", g);
	printf("Smallest element: %d\n", s);
}
int sumavg(int b[], int k){
	int x=0;
	if(k==0) return 0;
	else return b[k-1] + sumavg(b,k-1);
}
int main(){
	int num;
	printf("Enter the number of elements for array: ");
	scanf("%d", &num);
	int arr[num];
	printf("Enter your elements:\n");
	for(int i=0; i<num; i++) {scanf("%d", &arr[i]);}
	largesmall(arr,num);
	int total=sumavg(arr,num);
	int avg=total/num;
	printf("Sum: %d\nAvg: %d\n", total, avg);
return 0;
}
	
		
