#include <iostream>
using namespace std;

// Function to find the maximum value that can be obtained with the given capacity
int knapsack(int capacity, int weights[], int values[], int n)
{
    // Create a 2D array to store the maximum value at each n, capacity combination
    int dp[n + 1][capacity + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base case: no items or zero capacity
            else if (weights[i - 1] <= w)
            {
                // Item can be included
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                // Item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is found at dp[n][capacity]
    return dp[n][capacity];
}

int main()
{
    int values[] = {60, 100, 120};              // Values of items
    int weights[] = {10, 20, 30};               // Weights of items
    int capacity = 50;                          // Maximum capacity of the knapsack
    int n = sizeof(values) / sizeof(values[0]); // Number of items

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
