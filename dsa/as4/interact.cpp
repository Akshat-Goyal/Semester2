#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int x[N],r[N],w[N],idx[N],n,k;
map<int,int> ind;
vector<vector<int> > vals,bit;
int query2(int id,int i)
{
  int ans=0;
  while(i)
    {
      ans+=bit[id][i];
      i-=(i&(-i));
    }
  return ans;
}
int query(int idx)//in this wealth segtree, find new indexes of this nodes
{//find sum from (x-r to x+r)
  int l=max(0,x[idx]-::r[idx]);
  int r=x[idx]+::r[idx];
  int id=ind[w[idx]];
  int pl=lower_bound(vals[id].begin(),vals[id].end(),l)-vals[id].begin();
  if(pl==vals[id].size()) return 0;
  int pr=upper_bound(vals[id].begin(),vals[id].end(),r)-vals[id].begin();
  pr--;
  if(pl<pr) return 0;
  return query2(id,pr)-query2(id,pl-1);
}
long long solve(int idx)
{
  long long ans=0;
  for(int i=w[idx]-k;i<=w[idx]+k;i++)
    {
      if(!ind.count(i)) continue;
      ans+=query(idx);//calculate answer in segtree/BIT of this wealth
    }
  return ans;
}

void update(int ind,int pos,int val)//update pos index in ind^(th) BIT/segtree
{
  int sz=(int)bit[ind].size()-1;
  for(int i=pos;i<=sz;i+=(i&(-i)))
    bit[ind][i]+=val;
}
void update(int idx)
{
  int newidx=ind[w[idx]];
  int id=lower_bound(vals[newidx].begin(),vals[newidx].end(),x[idx])-vals[newidx].begin();
  update(newidx,id,1);
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
    {
      cin>>x[i]>>r[i]>>w[i]; idx[i]=i;
      ind[w[i]];
    }
  int cnt=0;
  for(auto &it:ind)//coordinate compression of w
    it.second=++cnt;
  vals.resize(cnt+1); bit.resize(cnt+1);
  for(int i=1;i<=n;i++)//for each w[i] push it's x[i] to its vector
    {
      int idx=ind[w[i]];
      vals[idx].push_back(x[i]);
    }
  for(int i=1;i<=cnt;i++)//make BIT/segtree for each distinct wealth
    {
      sort(vals[i].begin(),vals[i].end());
      bit[i].resize(vals[i].size(),0);
    }
  sort(idx+1,idx+n+1,[](int i,int j){return r[i]>r[j];});//sort in dec order or r
  long long ans=0;
  for(int i=1;i<=n;i++)
    {
      ans+=solve(idx[i]);
      update(idx[i]);
    }
  return 0 ;
}
