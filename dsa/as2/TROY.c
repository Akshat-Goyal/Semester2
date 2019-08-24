#include<stdio.h>

char s[1001][1001];
int t[1001];
int st[1001];

  int main(){
  //  int T;
  //  scanf("%d",&T);
  //  while(T--){
      int m,n,max=0;
      scanf("%d%d",&m,&n);
      for(int i=0;i<m;i++){
        char c;
        for(int j=0;j<n;j++)
          scanf("%c%c",&c,&s[i][j]);
      }
      for(int i=0;i<=n;i++)
        t[i]=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(s[i][j]=='E')
            t[j]=0;
          else t[j]++;
        }
        int k=-1;
        for(int j=0,temp;j<=n;j++){
          if(k==-1){
            st[++k]=j;
          }
          else if(t[j]>=t[st[k]]){
            st[++k]=j;
          }
          else{
            while(t[st[k]]>t[j] && k>=0){
              if(k>0)
                temp=(j-st[k-1]-1)*t[st[k]];
              else
                temp=j*t[st[k]];
              k--;
              max=max>=temp?max:temp;
            }
            st[++k]=j;
          }
        }
      }
      printf("%d\n",max);
   // }
    return 0;
  }
