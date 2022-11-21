#include <iostream>
using namespace std;
class Node;
void printList(Node *);
void push_begin(int, Node **);
void append(int, Node **);
void remove_top(Node **);
void del_end(Node **);
bool search(Node **, int);

int main()
{

    int key, choice, val;
    Node *head = NULL;

    cout << "Available options are:\n1. Insert at top.\n2. Insert at end.\n3. Delete from top.\n4. Delete from end.\n5 Search in list.\n6. Print list.\n0. Exit.\n\n";
    while (true)
    {
        cout << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            /* code */
            cout << "Enter the element: ";
            cin >> val;
            push_begin(val, &head);
            break;

        case 2:
            /* code */
            cout << "Enter the element: ";
            cin >> val;
            append(val, &head);
            break;

        case 3:
            /* code */
            remove_top(&head);
            break;

        case 4:
            /* code */
            del_end(&head);
            break;

        case 5:
            /* code */
            cout << "Enter the element to be searched: ";
            cin >> key;

            if (search(&head, key))
                cout << "Element exists in list!";
            else
                cout << "Element not found in lsit!";
            cout << endl;
            break;

        case 6:
            printList(head);
            break;
        case 0:
            return 0;
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << ", ";
        node = node->next;
    }
    cout << endl;
}

void push_begin(int new_data, Node **head_ref)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(int new_data, Node **head_ref)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    Node *temp = (*head_ref);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

void remove_top(Node **head_ref)
{
    Node *temp = (*head_ref);
    (*head_ref) = (*head_ref)->next;
    delete temp;
}

void del_end(Node **head_ref)
{
    Node *temp;
    Node *previous;
    temp = (*head_ref);

    while (temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    delete temp;
}

bool search(Node **head_ref, int key)
{
    Node *temp = *head_ref;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
            break;
        }
        temp = temp->next;
    }
    return false;
}