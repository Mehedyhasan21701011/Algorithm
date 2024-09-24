#include <bits/stdc++.h>
using namespace std;

void bubblesort(int array[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int array[] = {5, 3, 6, 1, 2, 7};
    int x = sizeof(array) / sizeof(array[0]);
    bubblesort(array, x);
}
