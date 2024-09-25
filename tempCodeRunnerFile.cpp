#include <bits/stdc++.h>
using namespace std;

#define V 5

void print_mst(int parent[V], int graph[V][V])
{
    for (int i = 0; i < V; i++)
    {
        cout << parent[i] << "--->" << graph[i][parent[i]] << endl;
    }
    cout << endl;
}

int min_key(bool mst_set[], int key[])
{
    int min = INT_MIN, min_index;
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
