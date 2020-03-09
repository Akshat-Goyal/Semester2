#include<stdio.h>

extern long fibonacci(long n);

int main(){
	long n;
	scanf("%ld",&n);
	printf("%ld\n",fibonacci(n));
	return 0;
}