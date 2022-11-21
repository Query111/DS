#include <bits/stdc++.h>
using namespace std;
int precendence(char);
void InToPre(string);
bool operand(char);
string rev(string);
int main()
{
    string infix;
    cout << "Enter infix string: ";
    cin >> infix;
    InToPre(infix);
}

int prec(char c)
{
    if (c == '$')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void InToPre(string infix)
{
    infix = rev(infix);
    stack<char> stk;

    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char expr = infix[i];
        if (operand(expr))
            postfix += expr;
        else if (expr == '(')
            stk.push(expr);
        else if (expr == ')')
        {
            while (stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while (!stk.empty() && prec(expr) < prec(stk.top()))
            {
                if (expr == '^' && stk.top() != '^')
                    break;
                else
                {
                    postfix += stk.top();
                    stk.pop();
                }
            }
            stk.push(expr);
        }
    }
    while (!stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }

    postfix = rev(postfix);
    cout << "Postfix string is: " << postfix << endl;
}

bool operand(char expr)
{
    if ((expr >= 'a' && expr <= 'z') || (expr >= 'A' && expr <= 'Z') || (expr >= '0' && expr <= '9'))
        return true;
    return false;
}

string rev(string str)
{
    int i = str.length() - 1;
    string res = "";
    while (i > -1)
    {
        if (str[i] == '(')
            res += ")";
        else if (str[i] == ')')
            res += "(";
        else
            res += str[i];
        i--;
    }
    return res;
}