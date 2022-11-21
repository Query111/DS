#include <bits/stdc++.h>
using namespace std;
// declaring function to convert to binary
string bin(int);

int main()
{
    int num;
    cout << "Enter the number(only positive): ";
    cin >> num;
    cout << "Binary equivalent of " << num << " is " << bin(num)<<endl;
}

string bin(int num)
{
    // creating an empty stack
    stack<int> bin;
    int rem;
    // pushing remainder on every iteration into stack
    while (true)
    {
        rem = num % 2;
        bin.push(rem);
        num /= 2;
        if (num == 0) // breaking the loop when number becomes zero
            break;
    }

    string res = "";
    // popping the stack into a string and that will be the binary equivalent of num
    while (!bin.empty())
    {
        res = res + to_string(bin.top());
        bin.pop();
    }
    // retuning the binary number as string
    return res;
}