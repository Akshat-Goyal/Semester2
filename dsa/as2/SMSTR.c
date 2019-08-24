#include<stdio.h>
#include<string.h>
char s[100001];
char t[100001];
int ar[256];

  int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
      ar[s[i]]++;
    int j=-1;
    for(int i=0,a=0;i<n;i++){
      while(ar[a]==0 && a<256)
        a++;
      while(j>=0 && a>=t[j]){
        printf("%c",t[j]);
        j--;
      }
      if(s[i]==a){
          printf("%c",s[i]);
          ar[a]--;
      }
      else{
          t[++j]=s[i];
          ar[s[i]]--;
      }
    }
    while(j>=0){
      printf("%c",t[j]);
      j--;
    }
    printf("\n");
    return 0;
  }
