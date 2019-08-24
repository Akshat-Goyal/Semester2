# TOPOLOGICAL SORT
---

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. 

## Idea
---

    If there is a path from node u to node v in a DAG, then 
    f(u) > f(v).
    So we will do dfs on graph and print all the nodes in decreasing order of their finishing times.

## Implementation
---

    We will do Depth First Search on DAG and push the node into the stack as soon as it finishes.
    After completing this process, we will pop the value from the stack and print it till the stack becomes empty. 

    Code in C++:

    Time Complexity:
        O(V + E)

```
#include<bits/stdc++.h>
using namespace std;


void dfs(vector<list<int> > &arr, stack<int> &st, vector<int> &visited, int s){
    
    list<int>::iterator it;
    for(it = arr[s].begin(); it != arr[s].end(); it++){
        if(visited[*it] == 0){
            visited[*it] = 1;
            dfs(arr, st ,visited ,*it);
        }
    }

    st.push(s);
}

void topoSort(vector<list<int> > &arr){

    int n = arr.size() - 1;

    vector <bool> visited(n + 1);          //initializing visited array to 0
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }

    stack <int> st;

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(arr, st, visited, i);
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();        
    }
}

    int main(){

        int n, m;                           // n is the total no. of nodes and m is the total no. of edges.              
        cin >> n >> m;

        vector<list<int> > arr(n + 1);        //Adjacency List representation of Graph

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
        }

        topoSort(arr);

        return 0;
    }

```