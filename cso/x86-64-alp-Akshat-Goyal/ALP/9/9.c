#include<stdio.h>

extern void merge(int*,int,int*,int,int*);

	int main(){
		int n,m;
		scanf("%d%d",&n,&m);
		int lista[n],listb[m],list[n+m];
		for(int i=0;i<n;i++){
			scanf("%d",lista+i);
		}
		for(int i=0;i<m;i++){
			scanf("%d",listb+i);
		}
		merge(lista,n,listb,m,list);
		for(int i=0;i<n+m;i++){
			printf("%d ",list[i]);
		} 
		printf("\n");
		return 0;
	}