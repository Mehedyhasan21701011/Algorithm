#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Selection_sort(int a[], int x)
{
    for (int i = 0; i < x; i++)
    {
        int min = i;
        for (int j = i + 1; j < x; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        swap(a[min], a[i]);
    }
}
int main()
{
    int array[] = {3, 40, 5, 61, 7, 51, 55, 6, 7};
    int x = sizeof(array) / sizeof(array[0]);
    Selection_sort(array, x);
    // using auto iterator
    for (auto &el : array)
    {
        cout << el << " ";
    }
}