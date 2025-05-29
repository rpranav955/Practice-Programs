#include <stdio.h>
int main(){
	FILE *fp;
	fp = fopen("file.txt","r");
	char data[20];
	
	if(fp==NULL){
		perror("ERROR");}
	else{
		while( !feof(fp)){fgets(data,20,fp);	printf("%s",data);}}
return 0;
}	
