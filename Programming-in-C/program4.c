#include <stdio.h>
int main(){
	int x,y,radius;
	printf("Enter your X-Coordinate:\n");
	scanf("%d",&x);
	printf("Enter your Y-Coordinate:\n");
	scanf("%d",&y);
	printf("Enter the radius of the circle:\n");
	scanf("%d",&radius);
	
	if((x*x)+(y*y)==(radius*radius)){
		printf("Your point lies on the circle.\n");}
	else if((x*x)+(y*y)>(radius*radius)){
		printf("Your point lies outside the circle.\n");}
	else if((x*x)+(y*y)<(radius*radius)){
		printf("Your point lies inside the circle.\n");}
	else{printf("Invalid Points\n");}
return 0;
}
