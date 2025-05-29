#include <stdio.h>
#include <string.h>
struct Student {
	char name[50];
	int adm;
};
int main(){
	int num;
	printf("Enter the number of students:\n");
	scanf("%d", &num);
	
	struct Student s[num];
	
	int adm;
	char name[50];
	
	for(int i=0; i<num; i++){
		printf("Name: ");
		scanf("%s", name);
		printf("Admission No.: ");
		scanf("%d", &adm);
		
		strcpy(s[i].name,name);
		s[i].adm=adm;
	}
	// Bubble sorting w.r.t name.
	int tempnum;
	char tempchar[50];
	for(int i=0; i<num-1; i++){
		for(int j=0; j<num-1-i; j++){
			if(strcmp(s[j].name,s[j+1].name) > 0){
			
				strcpy(tempchar,s[j].name); strcpy(s[j].name,s[j+1].name); strcpy(s[j+1].name,tempchar); 
				tempnum=s[j].adm; s[j].adm=s[j+1].adm; s[j+1].adm=tempnum; 
			}
		}
	}
	printf("Roll Number list:\n");
	for(int i=0; i<num; i++){
		printf("%d.\t %s \t%d\n", i+1, s[i].name, s[i].adm);
	}
return 0;
}
