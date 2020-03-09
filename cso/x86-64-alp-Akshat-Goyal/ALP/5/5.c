#include<stdio.h>

extern int sumN(int n);

	int main(){
		int n;
		scanf("%d",&n);
		printf("%d\n",sumN(n));
		return 0;
	}