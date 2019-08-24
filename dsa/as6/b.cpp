#include<bits/stdc++.h>
#define ll long long int
using namespace std;

typedef pair<ll,ll> pll;

vector<list<pll> >ar(100001);
ll visit[100001];

ll f=0;
ll val;

void fun(ll k,ll n){
	priority_queue<	pll , vector<pll> , greater<pll > > st;
	for(ll i=0,a;i<k;i++){
		cin>>a;
		st.push(make_pair(0,a));
		visit[a]++;
	}

	while(!st.empty()){
		pll c=st.top();
		ll a=c.first;
		ll b=c.second;
		st.pop();
		visit[b]++;
		if(visit[b]!=2){
			continue;
		}
		if(visit[b]==2 && b==0){
			f=1;
			val=a;
			break;
		}
		for(auto it=ar[b].begin();it!=ar[b].end();it++){
			st.push(make_pair(a+(*it).second,(*it).first));
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
		fun(k,n);
		if(f){
			cout << val << "\n";
		}
		else{
			cout << "-1\n";
		}
		return 0;
	}