
#include <iostream>
using namespace std;

// Function to add edges to the adjacency list
void add(int adj[][6], int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to print the adjacency matrix
void print(int adj[][6], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "-->";
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j])
            {
                cout << j << "    ";
            }
        }
        cout << endl;
    }
}

// Function to implement BFS without using STL
void BFS_function(int start, int adj[][6], int V)
{
    int result[6], visited[6] = {0}, queue[6];

    queue[0] = start;
    visited[0] = 1;

    // Print BFS result
    // cout << "BFS Result:" << endl;
    // for (int i = 0; i < index; i++) {
    //     cout << result[i] << "  ";
    // }
    // cout << endl;
}

int main()
{
    int V = 6;
    int adj[6][6] = {0}; // Adjacency matrix initialized to 0

    // Adding edges
    add(adj, 0, 1);
    add(adj, 1, 2);
    add(adj, 1, 5);
    add(adj, 2, 4);
    add(adj, 2, 3);
    add(adj, 5, 4);
    add(adj, 3, 4);

    // Print adjacency matrix
    print(adj, V);

    // Start BFS from vertex 0
    int start = 0;
    BFS_function(start, adj, V);

    return 0;
}
