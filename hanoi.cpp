#include <iostream>
using namespace std;

void hanoi(int n, string source, string target, string auxiliary);

int main()
{
    int n;
    cout << "Enter the size of tower : ";
    cin >> n;
    hanoi(n, "source", "target", "aux");
}

void hanoi(int n, string source, string target, string auxiliary)
{
    if (n > 0)
    {
        hanoi(n - 1, source, auxiliary, target);
        cout << "Moveing ring " << n << "  " << source << " -> " << target << "\n";
        hanoi(n - 1, auxiliary, target, source);
    }
}
