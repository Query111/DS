#include <iostream>
using namespace std;

//stack functions
class Node;
bool underflow = true;
void push(Node **, int);
int pop(Node **);
void remove(Node **);
bool isempty();
void print(Node*);
void peek(Node *);

int main()
{
    Node *stack=NULL;

    cout << "Available options are:\n1. Push element\n2. Pop element\n3. Remove element\n4. Check if stack is Empty\n5. Peek at stack\n6. Print the stack\n";
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
            push(&stack, key);
            break;
        case 2:
            /* code */
            pop(&stack);
            break;

        case 3:
            /* code */
            remove(&stack);
            break;

        case 4:
            /* code */
            cout << isempty();
            break;

        case 5:
            /* code */
            peek(stack);
            break;

        case 6:
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

class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    underflow = false;
}

int pop(Node **head_ref)
{
    if (underflow)
    {
        // underflow = true;
        cout << "No element in stack, cannot pop!" << endl;
        return 0;
    }
    Node *temp = (*head_ref);
    int val=temp->data;
    (*head_ref) = (*head_ref)->next;
    delete temp;
    cout<<val<<endl;
    return val;
}

void remove(Node ** head_ref)
{
    if (underflow)
    {
        cout << "No element in stack, cannot remove!" << endl;
        return;
    }
    Node *temp = (*head_ref);
    int val=temp->data;
    (*head_ref) = (*head_ref)->next;
    delete temp;
}

bool isempty()
{
    if (underflow)
        return true;
    else
        return false;
}

void print(Node *node)
{
    if (!underflow)
    {
        while (node != NULL)
    {
        cout << node->data << "\n---\n";
        node = node->next;
    }
    cout << endl;
    }
    else
        cout << "Stack is empty!\n";
}

void peek(Node *node)
{
    if(!underflow)
    cout << node->data << endl;
    else
    cout<<"Stack is empty\n";
}