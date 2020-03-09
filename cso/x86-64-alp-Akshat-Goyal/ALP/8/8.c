#include<stdio.h>

extern void reverse(char *str);

	int main(){
		char str[100000];
		scanf("%s",str);
		reverse(str);
		printf("%s\n",str);
		return 0;
	}