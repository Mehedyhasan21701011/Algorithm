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
