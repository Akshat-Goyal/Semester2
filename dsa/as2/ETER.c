#include<stdio.h>
#define ll long long int

ll ar[100000];
ll t[2][100001];

ll bi(ll l,ll r,ll x){
  if(l>r) return 0;
  ll b=(l+r)/2;
  if(t[0][b]>=x && (b==l || t[0][b-1]<x))
    return b;
  else if(t[0][b]<x)
    return bi(b+1,r,x);
  return bi(l,b-1,x);
}

  int main(){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++)
      scanf("%lld",ar+i);
    t[0][0]=ar[n-1];
    t[1][0]=n-1;
    ll st=0,en=0,x=ar[n-1];
    for(ll i=n-2;i>=0;i--){
      x=ar[i]+t[0][st];
      if((t[1][st]-i)>=k){
        st=(st+1);
      }
      if(x<t[0][st]){
        t[0][--st]=x;
        t[1][st]=i;
      }
      else if(x>t[0][en]){
        en=(en+1);
        t[0][en]=x;
        t[1][en]=i;
      }
      else{
          en=bi(st,en,x);
          t[0][en]=x;
          t[1][en]=i;
      }
    }
    printf("%lld\n",x);
    return 0;
 }
