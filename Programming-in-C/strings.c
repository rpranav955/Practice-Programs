#include <stdio.h>
#include <string.h>

int main(){
	
	char str1[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str2[]= " Hello woorld";
	char str3[20];
	
	printf("%ld\n", strlen(str1));
	printf("%ld\n", sizeof(str1));
	strcat(str1, str2);
	printf("%s\n", str1);
	strcpy(str3, str2);
	printf("%s\n", str3);
return 0;
}
