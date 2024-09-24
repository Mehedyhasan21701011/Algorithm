#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int array[] = {33, 44, 55, 77, 22, 33, 44, 7};
    int n = sizeof(array) / sizeof(array[0]);
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
    for (int &x : array)
    {
        cout << x << " ";
    }
}