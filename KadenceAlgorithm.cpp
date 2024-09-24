#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int sum = 0;
    int maxi = array[0];
    int start = -1, end = -1;
    for (int i = 0; i < 8; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum = sum + array[i];
        if (sum > maxi)
        {
            maxi = sum;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi << endl;
    cout << start << " " << end << endl;
    if (maxi > 0)
    {
        for (int i = start; i <= end; i++)
        {
            cout << array[i] << " ";
        }
    }
    else
    {
        cout << "\n[]" << endl;
    }

    return 0;
}