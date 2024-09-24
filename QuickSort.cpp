#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[end]);
    return i + 1;
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int p = partition(array, start, end);
        // cout << p << endl;
        quickSort(array, start, p - 1);
        quickSort(array, p + 1, end);
    }
}

int main()
{
    int array[] = {56, 3, 61, 2, 19, 51, 97};
    int n = sizeof(array) / sizeof(array[0]);
    int start = 0;
    int end = n - 1;
    quickSort(array, start, end);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "  ";
    }
}