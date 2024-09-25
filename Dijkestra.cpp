#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999 // A large value representing infinity

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int V, int src)
{
    int dist[MAX];    // Array to store the shortest distance from the source to each vertex
    bool sptSet[MAX]; // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as infinite and sptSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        sptSet[i] = false;
    }

    // Distance from the source to itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist[] of adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            // Update dist[v] if it's not in sptSet, there's an edge from u to v, and the total weight of path through u is smaller than the current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the calculated shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main()
{
    int V = 6;
    int graph[MAX][MAX] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 2},
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0}};

    dijkstra(graph, V, 0);
}
