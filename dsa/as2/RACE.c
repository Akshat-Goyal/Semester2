#include<stdio.h>
#define ll long long int

ll ar[100001],tt[100001];
ll q[2][100001];

ll v=0;
ll fun(ll n,ll t,ll k){
  v++;
  ll sum=0,st=0,en=0;
 // printf("time:%lld\n",t);
  for(ll i=n;i>=1;i--){
    ll x=t*tt[i]+ar[i];
   // printf("v:%lld x:%lld\n",v,x);
    while(i>=1 && q[1][st]>(i+k-1)){
      st++;
      if(st>en){
        st=en=0;
      }
    }
    if(st==0){
      q[0][++st]=x;
      q[1][st]=i;
      en++;
      //printf("st:%lld en:%lld\n",st,en);
    }
    else if(x>=q[0][st]){
      q[0][1]=x;
      q[1][1]=i;
      st=en=1;
    //  printf("st:%lld en:%lld\n",st,en);
    }
    else{
      while(q[0][en]<=x)
       en--;
      q[0][++en]=x;
      q[1][en]=i;
  //    printf("st:%lld en:%lld\n",st,en);
    }
    if((i+k-1)<=n){
      sum+=q[0][st];
    }
  }
    //printf("sum:%lld\n",sum);
    return sum;
}

  int main(){
    ll n,k,th;
    scanf("%lld%lld%lld",&n,&k,&th);
    for(ll i=1;i<=n;i++)
      scanf("%lld",ar+i);
    for(ll i=1;i<=n;i++)
      scanf("%lld",tt+i);
    ll l=0,r=1000000000,b=0;
    while(l<=r){
      b=(l+r)/2;
      ll sum=fun(n,b,k);
      if(sum<=th){
        l=b+1;
      }
      else{
        if(b==l || fun(n,b-1,k)<=th)
          break;
        r=b-1;
      }
    }
    printf("%lld\n",b);
    return 0;
  }
