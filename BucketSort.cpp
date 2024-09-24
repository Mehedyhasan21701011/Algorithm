#include <bits/stdc++.h>
using namespace std;

int getMax(int array[], int n)
{
    int largest = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }
    return largest;
}

void bucketSort(int array[], int n)
{
    int max = getMax(array, n);

    int bucket[max + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        bucket[array[i]]++;
    }

    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            array[j] = i;
            j++;

            bucket[i]--;
        }
    }
}

int main()
{
    int array[] = {15, 7, 8, 9, 13, 11};
    int n = sizeof(array) / sizeof(array[0]);

    bucketSort(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "  ";
    }
}