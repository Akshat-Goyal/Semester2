## Problem
---

Problem: Given a directed graph, with each node assigned a value. For every node v, find the sum of values of all such nodes u, such that u is reachable from v. 

### Idea
---

    Find sum of Strongly Connected Components - curr_node_value + sum of all the nodes that are reachable in the scc compressed -dag.

### Implementation
---

pseudocode in C++:

Step 1:
    
   Perform normal dfs on the given graph and store the node number in a stack according to their visiting time. This way the node with the highest finishing time will be on the top of the stack. 

```
    //adjList[] represents adjacency list of the given graph
    stack<ll> st;
     
    void dfs(ll start,vector<ll> adjList[],vector<bool> &visited)
    {
        visited[start]=true;
        for(ll i=0;i<adjList[start].size();i++)
        {
            ll vertex=adjList[start][i];
            if(visited[vertex]==false)
            {
                dfs(vertex,adjList,n_visited);
            }
        }
        st.push(start);
    }

```
Step 2:

    Perform another dfs operation for strongly connected component and store the nodes of a particular strongly connected component in a new vector named gr.

```
    //r_adjList - represents the adjacency list of reversed graph
    //scc_visited -visited vector required for dfs
    //group - represnts the strongly connected component
    //gr- this vector saves the nodes in a particular strongly connected component
    //parent[]- saves the group no for the node ,i.e, saving the representative of //node in strongly connected component
     
    ll group;
    vector<ll> gr;
    ll parent[MAX_LENGTH]={0};
     
    void scc_dfs(ll start,vector<ll> r_adjList[],vector<bool> &scc_visited)
    {
        scc_visited[start]=true;
        for(ll i=0;i<r_adjList[start].size();i++)
        {
            ll vertex=r_adjList[start][i];
            if(scc_visited[vertex]==false)
            {
                scc_dfs(vertex,r_adjList,scc_visited);
            }
        }
        gr[group].pb(start);
        parent[start]=group;
    }
```

Step 3:

    This is the main part of shrinking the graph.

    Again do the dfs traversal , and for each adjacent node u of a particular node v check that if that node u is a part of the same strongly connected component as that of v. That is check if both u and v belong to same strongly connected component. If that so dont add any edge, else add the edge between the two nodes u and v

```
    //visited[]- it is visited vector required for the dfs traversal
    //adjList_new[]- it saves the new adjacencey list for the condensed graph
    //adjList[] - old adjacency list
     
    void condense_graph_dfs(ll start,vector<ll> adjList[],vector<ll> adjList_new[],vector<bool> &visited)
    {
        visited[start]=true;
        for(ll i=0;i<adjList[start].size();i++)
        {
            ll vertex=adjList[start][i];
            ll p_start=parent[start];
            ll p_vertex=parent[vertex];
            if(p_start==p_vertex)
            {
                continue;
            }
            else
            {
                adjList_new[p_start].pb(p_vertex);
            }
            if(visited[vertex]==false)
                condense_graph_dfs(vertex,adjList,adjList_new,visited);
        }
    }
```
- After performing the condense_graph_dfs you get the new adjacency list for the condensed graph where nodes are the group no assigned during the dfs operation of strongly connected component. I hope this makes it clear to shrink strongly connected components into single nodes in the graph.

- Now we have strongly connected components and new adjacency list for the condensed graph .
- We can find sum of strongly connected components in O(n)
- Sum of all the nodes that are reachable in the scc compressed -dag can be find in O(n) by running bfs. 