#include<stdio.h>
#include<stdlib.h>

char t[100001];
char s[100001];

  int main(){
    int n; 
    scanf("%d",&n);
    scanf("%s",s);
    int i=-1,min=0;
    for(int j=0;j<n;j++){
      if(s[j]=='A'){
        t[++i]=s[j];
      }
      else if(s[j]=='C'){
        if(i>=0){
          i--;
        }
        else{
          t[++i]='A';
          min++;
        }
      }
    }
    if(i%2==0)
      printf("-1\n");
    else 
      printf("%d\n",min+(i+1)/2);
    return 0;
  }
