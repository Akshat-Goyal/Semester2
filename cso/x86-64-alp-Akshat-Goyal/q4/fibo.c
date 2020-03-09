#include<stdio.h>

extern long fibonacci(long N){
	long a0=0;
	long a1=1;
	for(long i=1;i<N;i++){
		long t=a1;
		a1+=a0;
		a0=t;
	}
	return a1;
}