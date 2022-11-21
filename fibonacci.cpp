#include <iostream>
using namespace std;

int fib(int);
int main()
{
    cout << "Enter number of terms: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << ", ";
    }
}

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}