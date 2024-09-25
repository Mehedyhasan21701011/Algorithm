#include <iostream>
#include <algorithm> // For sorting
using namespace std;

#define MAX 100 // Maximum number of vertices and edges

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// Function to find the parent of a node in the disjoint set
int findParent(int u, int parent[])
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent); // Path compression
}

// Function to perform union of two sets
void unionSets(int u, int v, int parent[], int rank[])
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

// Function to implement Kruskal's algorithm
void kruskalMST(Edge edges[], int V, int E)
{
    int parent[MAX], rank[MAX];

    // Initialize parent and rank arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort the edges by their weight
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int mstWeight = 0;
    cout << "Edges in the MST:\n";

    // Process each edge and add it to the MST if it doesn't form a cycle
    for (int i = 0; i < E; i++)
    {
        int u = findParent(edges[i].u, parent);
        int v = findParent(edges[i].v, parent);

        if (u != v)
        { // If u and v are in different sets, include the edge
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].weight << endl;
            mstWeight += edges[i].weight;
            unionSets(u, v, parent, rank); // Union the sets
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;
}

int main()
{
    int V = 6, E = 8; // Number of vertices and edges

    // Create an array of edges
    Edge edges[MAX] = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 5},
        {2, 4, 4},
        {3, 5, 3},
        {4, 5, 3}};

    // Call Kruskal's algorithm
    kruskalMST(edges, V, E);

    return 0;
}
