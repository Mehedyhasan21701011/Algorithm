#include <bits/stdc++.h>
using namespace std;

#define V 5

void print_mst(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int min_key(bool mst_set[], int key[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (!mst_set[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void prims_function(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mst_set[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mst_set[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = min_key(mst_set, key);
        mst_set[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mst_set[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    print_mst(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 1, 0, 0},
        {2, 0, 1, 0, 0},
        {1, 1, 0, 2, 2},
        {0, 0, 2, 0, 1},
        {0, 0, 2, 1, 0}};

    prims_function(graph);

    return 0;
}
