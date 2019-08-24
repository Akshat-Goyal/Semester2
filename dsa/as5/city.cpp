#include<bits/stdc++.h>
using namespace std;
#define ll int
typedef pair<ll, ll> pi;

ll co[5000001];
ll p;

void fun(vector<list<pi > >&ar,ll y){
	for(ll i=0;i<5000001;i++){
		co[i]=500000001;
	}
	co[y]=0;
	deque<ll>q;
	q.push_front(y);
	while(!q.empty()){
		ll a=q.front();
		q.pop_front();
		for(list<pi >::iterator it=ar[a].begin();it!=ar[a].end();it++){
				if(co[(*it).first]>co[a]+p*((*it).second)){
					co[(*it).first]=co[a]+p*((*it).second);
				
					if((*it).second==0){
						q.push_front((*it).first);
					}
					else{
						q.push_back((*it).first);
					}
				}
		}
	}
	
}

	int main(){
		ios_base::sync_with_stdio(0);
  	    cin.tie(0);
  	    cout.tie(0);
  	    ll n,m;
  	    cin>>n>>m>>p;
  	    vector<list<pi > >ar(n+1);
  	    for(ll i=0,a,b,c;i<m;i++){
  	    	cin>>a>>b>>c;
  	    	ar[a].push_back(make_pair(b,1-c));
  	    	ar[b].push_back(make_pair(a,1-c));
  	    }
  	    ll x,y;
  	    cin>>x>>y;
  	    fun(ar,x);
  	    if(co[y]==500000001){
  	    	co[y]=-1;
  	    }

  	    cout << co[y] << "\n";
  	    return 0;
	}