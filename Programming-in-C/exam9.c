#include <stdio.h>
struct student {
	int roll;
	char name[50];
	char gender;
	float cgpa;
}temporary, s[5];
int main(){
	s[0]=(struct student){50,"Pranav",'M',9.35};
	s[1]=(struct student){46,"Nitin",'M',8.5};
	s[2]=(struct student){63,"Vyshnav",'M',8.9};
	s[3]=(struct student){9,"Saji",'M',6.6};
	s[4]=(struct student){60,"Eeeee",'F',6.9};
	
	// Bubble sort in the order of their number of copies.
	for(int i=0; i<4; i++){
		for(int j=0; j<4-i; j++){
			if (s[j].cgpa<s[j+1].cgpa){
				temporary=s[j]; s[j]=s[j+1]; s[j+1]=temporary;
			}
		}	
	}
	
	// Print
	printf("Ranklist:\n");
		for(int i=0; i<5; i++){
			printf("%d.\t %d \t %s \t %c \t %f\n", i+1, s[i].roll, s[i].name, s[i].gender, s[i].cgpa);
		}
	printf("FAILED:\n");
		for(int i=0; i<5; i++){
			if(s[i].cgpa<7.0){printf("%d.\t %d \t %s \t %c \t %f\n", i+1, s[i].roll, s[i].name, s[i].gender, s[i].cgpa);}
		}		

return 0;
}
