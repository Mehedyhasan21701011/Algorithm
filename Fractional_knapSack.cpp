#include <iostream>
using namespace std;

// Structure to represent an item
struct Item
{
    int value;
    int weight;
};

// Comparator function to sort items based on value/weight ratio
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Sort in descending order
}

// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int capacity, Item items[], int n)
{
    // Sort items by value/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(items[j], items[j + 1]))
            {
                // Swap items if they are in the wrong order
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    double totalValue = 0.0; // Variable to store the total value

    for (int i = 0; i < n; i++)
    {
        // If adding the entire item doesn't exceed capacity
        if (items[i].weight <= capacity)
        {
            totalValue += items[i].value; // Add full value
            capacity -= items[i].weight;  // Decrease capacity
        }
        else
        {
            // If the item can't be added fully, add the fraction
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is full
        }
    }

    return totalValue; // Return the total value of knapsack
}

int main()
{
    Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}};
    int capacity = 50;                        // Maximum capacity of the knapsack
    int n = sizeof(items) / sizeof(items[0]); // Number of items

    double maxValue = fractionalKnapsack(capacity, items, n);
    cout << "Maximum value in Fractional Knapsack = " << maxValue << endl;

    return 0;
}
