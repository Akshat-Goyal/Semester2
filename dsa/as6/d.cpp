#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>path(1000001);
ll visit[1000001];
vector<list<pair<ll,ll> > >ar(1000001);

ll fl=0;

void dks(ll x,ll n){
	set<pair<ll,ll> > st;
	for(auto it=ar[x].begin();it!=ar[x].end();it++){
		if(visit[(*it).first]==1)
			continue;
		st.insert(make_pair((*it).second,(*it).first));
	}

	while(!st.empty() ){
		pair<ll,ll> a=*(st.begin());
		if(visit[a.second]==1){
			st.erase(st.begin());
			continue;
		}
		visit[a.second]=1;
		st.erase(st.begin());
		path[++fl]=a.first;
		for(auto it=ar[a.second].begin();it!=ar[a.second].end();it++){
			if(visit[(*it).first]==1){
				continue;
			}
			st.insert(make_pair((*it).second, (*it).first));
		}
	}
}

	int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n,m,k;
		cin>>n>>m>>k;
		for(ll i=0,a,b,c;i<m;i++){
			cin>>a>>b>>c;
			ar[a].push_back(make_pair(b,c));
			ar[b].push_back(make_pair(a,c));
		}
		visit[1]=1;	
		dks(1,n);
		if(fl<n-1){
			cout << "-1\n";
			return 0;
		}
		sort(path.begin()+1,path.begin()+n, greater<ll>());
		ll sum=0;
		for(ll i=1;i<n;i++){
			sum+=path[i];
		}
		ll f=0;
		for(ll i=1;sum>k && i<n;i++){
			f++;
			sum-=path[i]-1;
		}
		if(sum>k){
			f=-1;
		}
		cout << f << "\n";
		return 0;
	}