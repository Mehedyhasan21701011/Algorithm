#include <bits/stdc++.h>
using namespace std;

void add(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "-->";
        for (auto x : adj[i])
        {
            cout << x << "    ";
        }
        cout << endl;
    }
}
vector<int> BFS_function(int start, vector<int> adj[], int V)
{
    vector<int> result;
    vector<int> visited(V, 0);

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return result;
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

    print(adj, V);
    int start = 0;
    vector<int> bfs = BFS_function(start, adj, V);
    cout << "BFS rEsult:" << endl;
    for (auto x : bfs)
    {
        cout << x << "  ";
    }
    cout << endl;
}