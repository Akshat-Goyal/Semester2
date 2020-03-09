#include<stdio.h>

extern int countMovesHanoi(int);

	int main(){
		int n;
		scanf("%d",&n);
		printf("%d\n",countMovesHanoi(n));
		return 0;
	}