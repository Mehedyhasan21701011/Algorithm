#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int array[] = {5, 3, 6, 1, 2, 7};
    int x = sizeof(array) / sizeof(array[0]);

    clock_t start_time, end_time;

    start_time = clock(); // Get starting time

    for (int i = 1; i < x; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    end_time = clock(); // Get ending time

    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time taken by function: " << execution_time << " seconds" << endl;

    for (int i = 0; i < x; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
