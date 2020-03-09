#include<stdio.h>

extern int binarySearch(int*,int,int);

	int main(){
		int n;
		scanf("%d",&n);
		int ar[n];
		for(int i=0;i<n;i++){
			scanf("%d",ar+i);
		}
		int x;
		scanf("%d",&x);
		printf("%d\n",binarySearch(ar,n,x));
		return 0;
	}