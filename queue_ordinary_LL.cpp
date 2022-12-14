#include <iostream>
using namespace std;
class node;
void Insert();
void Delete();
void Display();

node *front = NULL;
node *rear = NULL;
node *temp;

int main()
{
    int ch;
    
    cout << "\n1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        cout<<endl;
        switch (ch)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
    return 0;
}

class node
{
    public:
    int data;
    struct node *next;
};

void Insert()
{
    int val;
    cout << "Insert the element in queue : " << endl;
    cin >> val;
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(class node));
        rear->next = NULL;
        rear->data = val;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(class node));
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
}
void Delete()
{
    temp = front;
    if (front == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (temp->next != NULL)
    {
        temp = temp->next;
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front = temp;
    }
    else
    {
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}
void Display()
{
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

