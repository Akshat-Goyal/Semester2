#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct tr{
	ll arl[9],arr[9];
	ll re,ans;
};

ll ar[100001];
tr seg[400020];
tr temp;

tr merge(tr a,tr b){
	tr k=temp;
	k.ans=a.ans+b.ans;
	for(ll i=0;i<9;i++){
		k.ans+=a.arr[i]*b.arl[(9-i)%9];
	}
	for(ll i=0;i<9;i++){
		k.arr[i]=b.arr[i];
		k.arl[i]=a.arl[i];
	}
	for(ll i=0;i<9;i++){
		k.arr[i]+=a.arr[(i-b.re+9)%9];
		k.arl[i]+=b.arl[(i-a.re+9)%9];
	}
	k.re=(a.re+b.re)%9;
	return k;
}

void build(ll pos,ll l,ll r){
	if(l==r){
		ll x=ar[l];
		seg[pos].re=x;
		seg[pos].arl[x]++;
		seg[pos].arr[x]++;
		seg[pos].ans=(x==0?1:0);
		return;
	}
	ll b=(l+r)/2;
	build(2*pos,l,b);
	build(2*pos+1,b+1,r);
	seg[pos]=merge(seg[2*pos],seg[2*pos+1]);
}

tr gett(ll pos,ll l,ll r,ll st,ll en){
	if(l>r || en<l || st>r)
		return temp;
	if(st<=l && en>=r){
		return seg[pos];
	}
	ll b=(l+r)/2;
	return merge(gett(2*pos,l,b,st,en),gett(2*pos+1,b+1,r,st,en));
}

void sett(ll pos,ll l,ll r,ll i,ll x){
	if(l>r)
		return;
	if(l==r){
		for(ll i=0;i<9;i++){
			seg[pos].arr[i]=0;
			seg[pos].arl[i]=0;
		}
		seg[pos].arr[x]++;
		seg[pos].arl[x]++;
		seg[pos].re=x;
		seg[pos].ans=x==0?1:0;
		return;
	}
	ll b=(l+r)/2;
	if(i<=b){
		sett(2*pos,l,b,i,x);
	}
	else{
		sett(2*pos+1,b+1,r,i,x);
	}
	seg[pos]=merge(seg[2*pos],seg[2*pos+1]);
}

ll modd(ll x,ll mo){
	x%=mo;
	ll y=mo-2,rem=1;
	while(y!=0){
		if(y%2==1){
			rem=(rem*x)%mo;
		}
		x=(x*x)%mo;
		y/=2;
	}
	return rem;
}

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

	int main(){
		ll n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		for(ll i=0;i<n;i++){
			ar[i+1]=(ll)(s[i]-'0')%9;
		}
		temp.ans=0;
		temp.re=0;
		for(ll i=0;i<9;i++){
			temp.arr[i]=0;
			temp.arl[i]=0;
		}
		build(1,1,n);
		while(q--){
			ll a,b,c;
			cin >> a >> b >> c;
			if(a==1){
				sett(1,1,n,b,c%9);
			}
			else{
				ll y=gett(1,1,n,b,c).ans;
				ll x=c-b+1;
				x=(x*(x+1))/2;
				ll g=gcd(x,y);
				y/=g;
				x/=g;
				x=modd(x,1000000007);
				y%=1000000007;
				y=(x*y)%1000000007;
				cout << y << "\n";
			}
		}
		return 0;

	}