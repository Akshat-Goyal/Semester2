#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<list<pair<ll,ll > > >ar(100001);
ll node[100001];
ll flag=0,n;

ll fun(ll x){
	ll mod=1000000007-1;
	ll r=x,y=x,rem=1;

	while(y!=0){
		if(y%2==1){
			rem=(rem*x)%mod;
		}
		x=(x*x)%mod;
		y/=2;
	}

	x = r;
	y = rem;
	rem = 1;
	mod++;

	while(y!=0)
	{
	  if(y%2==1){
			rem=(rem*x)%mod;
		}
		x=(x*x)%mod;
		y/=2;
	}

	return rem;
}

void dfs(ll x,ll y){
	for(auto it=ar[x].begin();it!=ar[x].end();it++){
		if(node[(*it).first]==0){
			node[(*it).first]=1;
			if(y==(*it).second){
				flag=1;
				return;
			}
			dfs((*it).first,(*it).second);
		}
	}
}

ll fun1(){
	unordered_map<ll,ll> m;
	for(ll i=1;i<=n;i++){
		if(node[i]==0){
			node[i]=1;
			m=unordered_map<ll,ll>(0);
			for(auto it=ar[i].begin();it!=ar[i].end();it++){
				ll co=m[(*it).second];
				if(co==0){
					m[(*it).second]=(*it).first;
				}
				else{
					if(node[co]==0){
						node[co]=1;
						dfs(co,(*it).second);
						if(flag==1){
							break;
						}
					}
					if(node[(*it).first]==0){
						node[(*it).first]=1;
						dfs((*it).first,(*it).second);
						if(flag==1){
							break;
						}
					}
				}
			}
			node[i]=0;
		}
		if(flag==1){
			break;
		}
	}
	ll total=0;
	for(ll i=1;flag==0 && i<=n;i++){
		if(node[i]==0){
			total++;
		}
	}
	cout << fun(total) << "\n";
}

	int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;
		for(ll i=0,u,v,c;i<n-1;i++){
			cin >> u >> v >> c;
			ar[u].push_back(make_pair(v,c));
			ar[v].push_back(make_pair(u,c));
		}
		fun1();
		return 0;

	}