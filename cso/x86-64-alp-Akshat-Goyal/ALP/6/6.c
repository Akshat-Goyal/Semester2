#include<stdio.h>

extern int isPrime(int n);	

	int main(){
		int n;
		scanf("%d",&n);
		printf("%d\n",isPrime(n));
		return 0;
	}