#include<stdio.h>

extern int parityCheck(long long int n);	

	int main(){
		long long int n;
		scanf("%lld",&n);
		printf("%d\n",parityCheck(n));
		return 0;
	}