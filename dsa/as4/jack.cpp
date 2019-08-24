#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll ar[50001];
ll ti[50000];
ll q[2][50000];

bool fun(ll k,ll t,ll n){
	q[0][0]=0;
	q[1][0]=1;
	ll st=0,en=0;
	for(ll i=2;i<=n;i++){
		ll x=q[0][st]+ti[i-2];
		while(st<=en && x<=q[0][en]){
			en--;
		}
		q[0][++en]=x;
		q[1][en]=i;
		while(q[1][st]<=(i-k)){
			st++;
		}
	}

	return (q[0][en]<=t);
}

ll bi(ll l,ll r,ll t,ll n){
	ll ans;
	while(l<=r){
		ll b=(l+r)/2;
		ll x=fun(b+1,t,n);
		
		if(x==1){
		j	j		ns=b;
			r=b-1;
		}
		else{
			l=b+1;
		}
	}
	ll max=ar[ans];
	for(ll i=ans+1;i<=n-2;i++){
		max=max<=ar[i]?max:ar[i];
	}
	return max;
}

	int main(){
		ll n,t;
		cin>>n>>t;
		for(ll i=0,x;i<n-1;i++){
			cin>>ar[i];
		}

		for(ll i=0;i<n-2;i++){
			cin>>ti[i];
		}
		ti[n-2]=0;t-=n-1;


		cout << bi(0,n-2,t,n) << "\n";
		return 0;
	}