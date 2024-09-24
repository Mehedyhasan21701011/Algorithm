#include <bits/stdc++.h>
using namespace std;
int Fibo(int a, int b)
{
    return a + b;
}
int main()
{
    int first = 0;
    int second = 1;
    cout << first << " " << second << " ";
    for (int i = 1; i <= 18; i++)
    {
        int fibo = Fibo(first, second);
        cout << fibo << " ";
        first = second;
        second = fibo;
    }
}