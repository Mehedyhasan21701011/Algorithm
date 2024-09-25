#include <iostream>
using namespace std;

#define INF 99999 // Define infinity as a large enough number
#define V 4       // Number of vertices

void floydWarshall(int graph[][V])
{
    // Create a distance array to store the shortest path distances
    int dist[V][V];

    // Initialize the distance array with the input graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the distance array using Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    // Define the graph as an adjacency matrix
    int graph[V][V] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    floydWarshall(graph);

    return 0;
}
