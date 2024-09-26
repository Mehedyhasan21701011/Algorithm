#include <bits/stdc++.h>
using namespace std;

void add(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs_call(int node, vector<int> adj[], int visited[], vector<int> &dfs_list)
{
    visited[node] = 1;
    dfs_list.push_back(node);
    for (auto x : adj[node])
    {
        if (!visited[x])
        {
            dfs_call(x, adj, visited, dfs_list);
        }
    }
}

void dfs_function(vector<int> adj[], int V)
{
    int start = 0;
    int visited[V] = {0};
    vector<int> dfs;
    dfs_call(start, adj, visited, dfs);

    cout << "DFS Result:" << endl;
    for (auto x : dfs)
    {
        cout << x << "    ";
    }
}
int main()
{
    int V = 6;
    vector<int> adj[V];
    add(adj, 0, 1);
    add(adj, 1, 2);
    add(adj, 1, 5);
    add(adj, 2, 4);
    add(adj, 2, 3);
    add(adj, 5, 4);
    add(adj, 3, 4);
    dfs_function(adj, V);
}