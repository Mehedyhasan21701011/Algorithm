#include <bits/stdc++.h>
using namespace std;

int findMax(int array[], int n)
{
    int largest = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }
    return largest;
}

void countSort(int array[], int n)
{
    int max = findMax(array, n);
    int countArray[max + 1];
    int outPutArray[n + 1];

    for (int i = 0; i <= max; i++)
    {
        countArray[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        countArray[array[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        countArray[i] = countArray[i] + countArray[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        outPutArray[countArray[array[i]] - 1] = array[i];
        countArray[array[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = outPutArray[i];
    }
}

int main()
{
    int array[] = {7, 2, 5, 3, 9, 8};
    int n = sizeof(array) / sizeof(array[0]);

    countSort(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "  ";
    }
    return 0;
}