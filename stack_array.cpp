#include <iostream>
using namespace std;
int stack[123], n = 123, top = -1;
bool overflow = false, underflow = true;
void push(int[], int);
int pop(int[]);
void remove(int[]);
bool isempty(int[]);
void print(int[]);
void peek(int[]);
bool isfull(int[]);

int main()
{

    cout << "Available options are:\n1. Push element\n2. Pop element\n3. Remove element\n4. Check if stack is Empty\n5. Check if stack is full\n6. Peek at stack\n7. Print the stack\n";
    int choice, key;
    while (true)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            /* code */
            cout << "Enter the element to be pushed: ";
            cin >> key;
            push(stack, key);
            break;
        case 2:
            /* code */
            pop(stack);
            break;

        case 3:
            /* code */
            remove(stack);
            break;

        case 4:
            /* code */
            cout << isempty(stack);
            break;

        case 5:
            /* code */
            cout << isfull(stack);
            break;

        case 6:
            /* code */
            peek(stack);
            break;

        case 7:
            /* code */
            print(stack);
            break;

        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
}

void push(int arr[], int key)
{
    if (top >= n - 1)
    {
        overflow = true;
        cout << "Overflow detected, cannot add more elements! " << endl;
        return;
    }
    arr[++top] = key;
    underflow = false;
}

int pop(int arr[])
{
    if (underflow)
    {
        // underflow = true;
        cout << "No element in stack, cannot pop!" << endl;
        return 0;
    }
    int temp = arr[top];
    top--;
    cout << temp;
    return temp;
}

void remove(int arr[])
{
    if (top == -1)
    {
        underflow = true;
        cout << "No element in stack, cannot remove!" << endl;
        return;
    }
    top--;
}

bool isempty(int arr[])
{
    if (underflow)
        return true;
    else
        return false;
}

void print(int arr[])
{
    if (!underflow)
    {
        for (int i = top; i > -1; i--)
        {
            cout << arr[i] << endl
                 << "---\n";
        }
    }
    else
        cout << "Stack is empty!\n";
}

void peek(int arr[])
{
    if (underflow)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << arr[top] << endl;
}

bool isfull(int arr[])
{
    if (overflow)
        return true;
    else
        return false;
}