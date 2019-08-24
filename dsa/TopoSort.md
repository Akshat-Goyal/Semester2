## Problem

    Find lexicographically smallest topological sort of a DAG

### Idea
    
    - We will use bfs(using heap or priority queue) instead of dfs for this. 
    - The idea is to first output the nodes with indegree 0 in increasing order. 
    - Remove them and their outgoing edges. We now have a new set of nodes with indegree 0 which are the children of the earlier.
    - You maintain an AdjList along with the current indegree of each node. 
    - Keep a priority queue/heap which is the set of nodes with indegree 0.
    - Each time you pick a node whose indegree is 0, pop it from heap/priority_queue, reduce indegree of all nodes adjancent to it. While reducing the indegree if any node indegree turns 0 add it to the queue.

### Implementation

    Code in C++:

```
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll  in_degree[100001];                  //current indegree of each node
ll  visit[100001];
ll  tSort[100001];

void topoSort(auto &ar){
    ll n=ar.size()-1;                   //n=no.of nodes

    priority_queue<ll,vector<ll>,greater<ll> >pq;

    for(ll i = 1; i <= n; i++){         //Create a priority queue and  insert all vertices with indegree 0 to it.
        if(in_degree[i] == 0){
            visit[i] = 1;               //marking a vertex visited if pushed in pq
            pq.push(i);
        }
    }

    queue<ll> q;                
    ll cnt=0;                           //cnt of no. of vertices in tSort
         
    while(!pq.empty()){
        ll t = pq.top();                //extracting top of pq 
        pq.pop();

        tSort[++cnt] = t;               // and add it to tSort

                                        // iterate through all its neighbouring nodes of dequeued node t 
        for(auto it = ar[t].begin(); it != ar[t].end(); it++){
            if(visit[*it] == 0){
                if(--in_degree[*it] == 0){          //and decrease by 1
                    visit[*it] = 1;                 //if indegree == 0, add it to queue
                    q.push(*it);                    // mark it as visited
                }
            }
        }

        if(pq.empty()){                     // if pq becomes empty, push all elements of q to pq
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
    }
}

    int main(){

        int n, m;
        cin >> n >> m;                  // n is no. of nodes and m is no. of edges

        vector < list < ll > > ar(n+1);

        for(ll i=0, u, v; i < m ;i++){
            cin >> u >> v;
            ar[u].push_back(v);
            in_degree[v]++;
        }

        topoSort(ar);

        for(ll i=1;i<=n;i++){               //printing topological sort
            cout << tSort[i] << " ";
        }
        cout << "\n";

        return 0;
    }

```