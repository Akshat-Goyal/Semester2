#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

bool visit[100001];
bool cont[100001];

void dfs(vector<list<ll> > &ar,ll x,stack<ll> &st){
	visit[x]=1;
	for(list<ll>::iterator it=ar[x].begin();it!=ar[x].end();it++){
		if(visit[*it]==0){
			dfs(ar,*it,st);
		}
	}
	st.push(x);
}

ll f=0;

void dfs1(vector<list<ll> > &ar,ll x){
	f++;
	visit[x]=1;
	cont[x]=1;
	for(list<ll>::iterator it=ar[x].begin();it!=ar[x].end();it++){
		if(visit[*it]==0){
			dfs1(ar,*it);
		}
	}
}

void fun(vector<list<ll> > &ar,stack<ll> &st){
	ll n=ar.size()-1;
	vector<list<ll> > gr(n+1);
	for(ll i=1;i<=n;i++){
		list<ll>::iterator it;
		for(it=ar[i].begin();it!=ar[i].end();it++){
			gr[*it].push_back(i);
		}
	}
	for(ll i=1;i<=n;i++){
		visit[i]=0;
	}
	for(ll i=1;i<=n;i++){
		ll t=st.top();
		st.pop();
		if(visit[t]==0){
			f=0;
			dfs1(gr,t);
			if(f==1){
				cont[t]=0;
			}
		}
	}
}

	int main(){
		ios_base::sync_with_stdio(0);
  	 	cin.tie(0);
  	 	cout.tie(0);
  	 	ll n,m;
  	 	cin >> n >> m;
  	 	vector<list<ll> > ar(n+1);
  	 	for(ll i=0;i<m;i++){
  	 		ll a,b;
  	 		cin >> a >> b;
  	 		ar[a].push_back(b);
  	 	}
  	 	stack<ll> st;
  	 	for(ll i=1;i<=n;i++){
  	 		if(visit[i]==0){
  	 			dfs(ar,i,st);
  	 		}
  	 	}
  	 	fun(ar,st);
  	 	for(ll i=1;i<=n;i++){
  	 		cout << cont[i] << " ";
  	 	}
  	 	cout << "\n";
  	 	return 0;
 	}