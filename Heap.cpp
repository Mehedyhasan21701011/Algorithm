#include <bits/stdc++.h>
using namespace std;

void heapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array, n, largest);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    int array[] = {81, 89, 9, 11, 14, 76, 54, 22};
    int n = sizeof(array) / sizeof(array[0]);
    heapsort(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}