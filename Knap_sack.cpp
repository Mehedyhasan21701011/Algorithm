#include <iostream>

using namespace std;

// Function to swap two items
void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by profit/weight ratio
void sortItems(int n, double profit[], double weight[], double ratio[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                // Swap ratio, profit, and weight
                swap(&ratio[j], &ratio[j + 1]);
                swap(&profit[j], &profit[j + 1]);
                swap(&weight[j], &weight[j + 1]);
            }
        }
    }
}

// Function to calculate the maximum profit using fractional knapsack
double fractionalKnapsack(int n, double profit[], double weight[], double capacity)
{
    double totalProfit = 0.0;
    double ratio[n];

    // Calculate profit/weight ratio for each item
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    sortItems(n, profit, weight, ratio);

    for (int i = 0; i < n; i++)
    {
        if (capacity >= weight[i])
        {
            capacity -= weight[i];
            totalProfit += profit[i];
        }
        else
        {
            // Add fractional part of the item
            totalProfit += profit[i] * (capacity / weight[i]);
            break;
        }
    }

    return totalProfit;
}

int main()
{
    // Number of items
    int n = 7; // Corrected to 7 to match the number of items in the arrays

    // Arrays for profits and weights
    double profit[] = {10, 5, 15, 7, 6, 18, 3};
    double weight[] = {2, 3, 5, 7, 1, 4, 1};

    // Capacity of the knapsack
    double capacity = 15;

    // Calculate and display the maximum profit
    double maxProfit = fractionalKnapsack(n, profit, weight, capacity);

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
