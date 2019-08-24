#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct tr{
	ll ans;
};
ll mod=1000000007;
ll ar[100001];
ll inc[100001];
ll der[100001];
tr seg[400021];

tr merge(tr a,tr b){
	tr k;
	k.ans=(a.ans+b.ans)%mod;
	return k;
}

tr get1(ll pos,ll l,ll h,ll st,ll en){
	if(l>en || h<st){
		tr k={0};
		return k;
	}
	if(st<=l && en>=h){
		return seg[pos];
	}
	ll b=(l+h)/2;
	return merge(get1(2*pos,l,b,st,en),get1(2*pos+1,b+1,h,st,en));
}

void set1(ll pos,ll l,ll h,ll i,ll x){
	if(l==h){
		seg[pos].ans+=x;
		// cout << seg[pos].ans << "\n";
		return;
	}
	ll b=(l+h)/2;
	if(i<=b){
		set1(2*pos,l,b,i,x);
	}
	else{
		set1(2*pos+1,b+1,h,i,x);
	}
	seg[pos]=merge(seg[2*pos],seg[2*pos+1]);
	return;
}


bool compare(const ll &a,const ll &b){
	return ar[a]<=ar[b];
}

	int main(){
		ios_base::sync_with_stdio(0);
  	    cin.tie(0);
  	    cout.tie(0);
		ll n;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>ar[i];
			inc[i]=i;
		}
		sort(inc+1,inc+1+n,compare);
		ll max=1;
		for(ll i=1;i<=n;i++){
			ll temp=ar[inc[i]];
			ar[inc[i]]=max;
			if(i<n && ar[inc[i+1]]!=temp){
				max++;
			}
		}
		for(ll i=1;i<=max;i++){
			inc[i]=0;
		}
		for(ll i=1;i<=n;i++){
			inc[i]=get1(1,1,max,1,ar[i]).ans+1;
			// cout << inc[i] << " ";
			set1(1,1,max,ar[i],inc[i]%mod);
		}
		// cout << "\n";
		for(ll i=1;i<=400020;i++){
			seg[i].ans=0;
		}
		for(ll i=n;i>=1;i--){
			if(ar[i]==1)
				der[i]=1;
			else
				der[i]=get1(1,1,max,1,ar[i]-1).ans+1;
			ll temp=get1(1,1,max,1,ar[i]).ans+1;
			// cout << "dec " << der[i] << " ";
			set1(1,1,max,ar[i],temp%mod);
		}
		// cout << "\n";
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll temp=(inc[i]%mod*der[i]%mod)%mod;
			ans=(ans+temp)%mod;
		}
		cout << ans << "\n";
		return 0;
	}