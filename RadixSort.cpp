#include <bits/stdc++.h>
using namespace std;

int getMax(int array[], int n)
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

void countingSort(int array[], int n, int place)
{
    int output[n + 1];
    int countArray[10] = {0};

    for (int i = 0; i < n; i++)
    {
        countArray[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        countArray[i] += countArray[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[countArray[(array[i] / place) % 10] - 1] = array[i];
        countArray[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}

void radixSort(int array[], int n)
{
    int max = getMax(array, n);
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(array, n, place);
    }
}

int main()
{

    int array[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};
    int n = sizeof(array) / sizeof(array[0]);

    radixSort(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "  ";
    }
}