#include <stdio.h>
#include <string.h>
// Declaring the structure.
struct Student{
	int adm;
	char name[50];
	};

int main(){
	int num;
	printf("Enter the number of students:\n");
	scanf("%d", &num);
	struct Student s[num];
	for(int i=0; i<num; i++){
	char name[50];
	int adm;
		printf("\n");
		printf("Name: ");
		scanf("%s", name);
		printf("Admission Number: ");
		scanf("%d", &adm);
		strcpy(s[i].name,name);
		s[i].adm=adm;
		}
		
	for(int i=0; i<num-1; i++){
		for(int j=0; j<num-i-1; j++){
			if (strcmp(s[j].name, s[j+1].name) > 0) {
					char tempn[50];
				strcpy(s[j].name,tempn);
				strcpy(s[j].name,s[j+1].name);
				strcpy(s[j+1].name,tempn);
					int tempa;
				tempa=s[j].adm;
				s[j].adm=s[j+1].adm;
				s[j+1].adm=tempa;
			}
		}
	}
	
	printf("\n");
	
	printf("Roll number list:\n");
	for(int i=0; i<num; i++){
		printf("%d.\t %s \t%d", i+1, s[i].name, s[i].adm);
		printf("\n");
	}
return 0;
}
