#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node{
	ll oe[2];
};

vector<ll>str(200001);
ll visit[200001];
ll tim[2][200001];
ll ar[400010];
node seg[1600020];

ll fl=0;
void dfs(auto &ar1,ll x){
	ar[++fl]=x;
	tim[0][x]=fl;
	for(auto it=ar1[x].begin();it!=ar1[x].end();it++){
		if(visit[*it]==0){
			visit[*it]=1;
			dfs(ar1,(*it));
		}
	}
	ar[++fl]=x;
	tim[1][x]=fl;
}

void sett(ll pos,ll l,ll h,ll st,ll en,ll b,ll x){
	if(st > h || en < l){
		return;
	}
	if(st<=l && en>=h){
		seg[pos].oe[tim[0][b]%2]+=x;
		seg[pos].oe[(tim[0][b]+1)%2]-=x;
		return;
	}
	ll mid=(l+h)/2;
	sett(2*pos,l,mid,st,en,b,x);
	sett(2*pos+1,mid+1,h,st,en,b,x);
	return;
}

ll get(ll pos,ll l,ll h,ll i,ll b){
	if(l==h){
		return seg[pos].oe[tim[0][b]%2];
	}
	ll mid=(l+h)/2;
	ll ans=seg[pos].oe[tim[0][b]%2];
	if(i<=mid){
		ans+=get(2*pos,l,mid,i,b);
	}
	else{
		ans+=get(2*pos+1,mid+1,h,i,b);
	}
	return ans;
}

	int main(){
			ios::sync_with_stdio(false)
			cin.tie(NULL);
			cout.tie(NULL);
			ll n,m;
			cin>>n>>m;
			vector<list<ll> >ar1(n+1);
			for(ll i=1;i<=n;i++){
				cin >> str[i];
			}
			for(ll i=1,a,b;i<n;i++){
				cin>>a>>b;
				ar1[a].push_back(b);
				ar1[b].push_back(a);
			}
			visit[1]=1;
			dfs(ar1,1);
			while(m--){
				ll a,b,c;
				cin >> a;
				if(a==1){
					cin >> b >> c;
					sett(1,1,2*n,tim[0][b],tim[1][b],b,c);
				}
				else{
					cin >> b;
					cout << get(1,1,2*n,tim[0][b],b)+str[b] << "\n";
				}
			}
			return 0;
	}