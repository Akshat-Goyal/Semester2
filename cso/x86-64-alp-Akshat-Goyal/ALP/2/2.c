#include<stdio.h>

extern int max(int *ar,int n,int m);	

	int main(){
		int n,m;
		scanf("%d%d",&n,&m);
		int ar[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&ar[i][j]);
			}
		}
		printf("%d\n",max((int *)ar,n,m));
		return 0;
	}