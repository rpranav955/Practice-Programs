#include <stdio.h>
struct book {
	int id;
	char name[50];
	char aname[50];
	int copy;
}temporary, b[4];
int main(){
	b[0]=(struct book){111,"aaa","auth1",3};
	b[1]=(struct book){222,"bbb","auth2",2};
	b[2]=(struct book){333,"ccc","auth3",4};
	b[3]=(struct book){444,"ddd","auth4",1};
	
	// Bubble sort in the order of their number of copies.
	for(int i=0; i<3; i++){
		for(int j=0; j<3-i; j++){
			if (b[j].copy>b[j+1].copy){
				temporary=b[j]; b[j]=b[j+1]; b[j+1]=temporary;
			}
		}	
	}
	
	// Print
		for(int i=0; i<4; i++){
			printf("%d.\t %d \t %s \t %s \t %d\n", i+1, b[i].id, b[i].name, b[i].aname, b[i].copy);
		}		

return 0;
}
