#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll path1[100001];
ll path2[100001];
ll path3[100001];
ll path4[100001];
ll visit[100001];

void dks(auto &ar,ll x,ll n,auto &path){
	set<pair<ll,ll> > st;
	for(ll i=1;i<=n;i++){
		st.insert(make_pair(1000000000,i));
		path[i]=1000000000;
	}
	st.erase(st.find(make_pair(path[x],x)));
	st.insert(make_pair(0,x));
	path[x]=0;
	while(!st.empty()){
		pair<ll,ll> a=*(st.begin());
		st.erase(st.begin());
		visit[a.second]=1;
		for(auto it=ar[a.second].begin();it!=ar[a.second].end();it++){
			if(visit[(*it).first]==1){
				continue;
			}
			auto p=st.find(make_pair(path[(*it).first],(*it).first));
			if((*p).first>a.first+(*it).second){
				st.erase(p);
				path[(*it).first]=a.first+(*it).second;
				st.insert(make_pair(path[(*it).first],(*it).first));
			}
		}
	}
	for(ll i=1;i<=n;i++){
		visit[i]=0;
	}
}

	int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n,m,s,t;
		cin>>n>>m>>s>>t;
		vector<list<pair<ll,ll> > >ar(n+1);
		vector<list<pair<ll,ll> > >ar1(n+1);
		for(ll i=0,a,b,c;i<m;i++){
			cin>>a>>b>>c;
			ar[a].push_back(make_pair(b,c));
			ar1[b].push_back(make_pair(a,c));
		}
		dks(ar,s,n,path1);
		dks(ar1,t,n,path2);
		dks(ar,t,n,path3);
		dks(ar1,s,n,path4);
		ll min=1000000000;
		for(ll i=1;i<=n;i++){
			if(i==s || i==t){
				continue;
			}
			ll x=1000000000;
			if(path1[i]==x || path2[i]==x || path3[i]==x || path4[i]==x){
				continue;
			}
			ll y=path1[i]+path2[i]+path3[i]+path4[i];
			min=min<=y?min:y;
		}
		if(min==1000000000){
			min=-1;
		}
		cout << min << "\n";
		return 0;
	}