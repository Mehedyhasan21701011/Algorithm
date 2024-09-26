#include <bits/stdc++.h>
using namespace std;
#define V 5

void add(vector<int> adj[V], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> apply_bfs(vector<int> adj[V], int start)
{
    vector<int> res;
    vector<int> visited(V, 0);
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> adj[V];
    add(adj, 0, 1);
    add(adj, 0, 4);
    add(adj, 0, 3);
    add(adj, 1, 2);
    add(adj, 3, 2);
    add(adj, 2, 4);

    int start = 0;
    vector<int> result = apply_bfs(adj, start);

    for (auto it : result)
    {
        cout << it << "    ";
    }
}