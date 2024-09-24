#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {9, 11, 3, 2, 1, 8, 3};
    int n = 7;
    int mini = array[0];
    int profit = 0;
    int cost = 0;
    for (int i = 1; i < n; i++)
    {
        cost = array[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, array[i]);
    }
    cout << profit << endl;
}
