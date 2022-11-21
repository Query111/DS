#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int n = 123, top = -1;

bool overflow = false, underflow = false;
void push(string[], string);
string pop(string[]);
bool operand(string);
string eval(string, string, string);

int main()
{
    string stack[n];
    int i = 0;
    string post, expr, infix;
    cout << "Enter valid postfix expression: ";
    cin >> post;
    string opt1, opt2;
    while (i < post.length())
    {
        expr = post[i];
        if (operand(expr))
            push(stack, expr);
        else
        {
            opt1 = pop(stack);
            opt2 = pop(stack);
            push(stack, eval(expr, opt1, opt2));
        }
        i++;
    }
    cout << "Evaluation is: " << pop(stack);

}

void push(string arr[], string key)
{
    if (top >= n - 1)
    {
        overflow = true;
        cout << "Overflow detected, cannot add mande elements! " << endl;
        return;
    }
    arr[++top] = key;
}

string pop(string arr[])
{
    if (top == -1)
    {
        underflow = true;
        cout << "No element in stack, cannot pop!" << endl;
        return 0;
    }
    string temp = arr[top];
    top--;
    return temp;
}

bool operand(string expr)
{
    if (expr != "+" and expr != "-" and expr != "*" and expr != "/" and expr != "$" and expr != "%")
        return true;
    else
        return false;
}

string eval(string expr, string op1, string op2)
{
    int opt1 = stoi(op1);
    int opt2 = stoi(op2);
    int val;

    if (expr == "+")
        val = opt1 + opt2;

    else if (expr == "-")
        val = opt2 - opt1;

    else if (expr == "*")
        val = opt2 * opt1;

    else if (expr == "/")
        val = opt2 / opt1;

    else if (expr == "$")
        val = pow(opt2, opt1);

    else if (expr == "%")
        val = opt2 % opt1;

    return to_string(val);
}