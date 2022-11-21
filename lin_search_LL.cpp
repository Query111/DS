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

    push_begin(23, &head);
    append(31, &head);
    append(53, &head);
    append(4, &head);
    append(11, &head);
    append(1, &head);
    
    cout << "Enter the element to be searched: ";
    cin >> key;

    if (search(&head, key))
        cout << "Element exists in list!";
    else
        cout << "Element not found in lsit!";
    cout << "\nList is: ";
    printList(head);
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