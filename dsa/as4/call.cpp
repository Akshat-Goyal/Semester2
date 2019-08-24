#include<bits/stdc++.h>
using namespace std;
#define ll long long int

	int main(){
		ios_base::sync_with_stdio(0);
  	    cin.tie(0);
  	    cout.tie(0);
  	    ll n;
  	    cin>>n;
  	    unordered_map<string, ll> name;
  	    unordered_set<string> tset;
  	    for(ll i=0;i<n;i++){
  	    	string s;
  	    	cin >> s;
        	name[s]++;
  	    }
  	    ll q;
  	    cin >> q;
  	    for(ll i=0;i<q;i++){
  	    	string s;
  	    	cin >> s;
  	    	tset=unordered_set<string>(0);
  	    	ll le=s.length();
  	    	ll que=0;
  	    	ll ar[3];
  	    	for(ll j=0;j<le;j++){
  	    		if(s[j]=='?'){
  	    			ar[que]=j;
  	    			que++;
  	    		}
  	    	}
  	    	ll ans=0;
  	    	if(que==1){
  	    		for(ll j=0;j<5;j++){
  	    			s[ar[0]]='a'+j;
  	    			ans+=name[s];
  	    		}
  	    		string ss=s;
  	    		ss.erase(ar[0],1);
  	    		ans+=name[ss];
  	    		cout << ans << "\n";
  	    	}
  	    	else if(que==2){
  	    		string ss="";
  	    		ll arr[3];
  	    		for(ll b=0;b<3;b++){
  	    			arr[b]=ar[b];
  	    		}
  	    		for(ll j=0,k;j<6;j++){
  	    			if(j!=5){
  	    				s[ar[0]]='a'+j;
  	    				ss=s;
  	    			}
  	    			else{
  	    				ss=s;
  	    				ss.erase(ar[0],1);
  	    				arr[1]--;		
  	    			}
  	    			for(k=0;k<6;k++){
  	    				string sss="";
  	    				if(k!=5){
  	    					ss[arr[1]]='a'+k;
  	    					sss=ss;
  	    				}
  	    				else{
  	    					sss=ss;
  	    					sss.erase(arr[1],1);
  	    				}
  	    				if(tset.find(sss)==tset.end()){
  	    					tset.insert(sss);
  	    					ans+=name[sss];
  	    				}
  	    			}
  	    		}
  	    		cout << ans << "\n";
  	    	}
  	    	else if(que==3){
  	    		for(ll j=0,k,l;j<6;j++){
  	    			string ss="";
  	    			ll arr[3];
  	    			for(ll b=0;b<3;b++){
  	    				arr[b]=ar[b];
  	    			}
  	    			if(j!=5){
  	    				s[ar[0]]='a'+j;
  	    				ss=s;
  	    			}
  	    			else{
  	    				ss=s;
  	    				ss.erase(ar[0],1);
  	    				arr[1]--;
  	    				arr[2]--;		
  	    			}
  	    			for(k=0;k<6;k++){
  	    				string sss="";
  	    				ll arrr[3];
  	    				for(ll b=0;b<3;b++){
  	    					arrr[b]=arr[b];
  	    				}
  	    				if(k!=5){
  	    					ss[arr[1]]='a'+k;
  	    					sss=ss;
  	    				}
  	    				else{
  	    					sss=ss;
  	    					sss.erase(arr[1],1);
  	    					arrr[2]--;		
  	    				}
  	    				for(l=0;l<6;l++){
  	    					string ssss="";
  	    					if(l!=5){
  	    						sss[arrr[2]]='a'+l;
  	    						ssss=sss;
  	    					}
  	    					else{
  	    						ssss=sss;
  	    						ssss.erase(arrr[2],1);	
  	    					}
  	    					if(tset.find(ssss)==tset.end()){
  	    						tset.insert(ssss);
  	    						ans+=name[ssss];
  	    					}
  	    				}
  	    			}
  	    		}
  	    		cout << ans << "\n";
  	    	}
  	    	else{
  	    		cout << name[s] << "\n";
  	    	}
  	    }
  	    return 0;
	}