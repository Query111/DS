#include <iostream>
using namespace std;
int front = -1;
int rear = -1;
void enqueue(float[], int, float);
float dequeue(float[], int);
void display(float[], int);

int main()
{
    int size;
    cout << "Enter the size of your queue: ";
    cin >> size;
    float queue[size], data;
    cout << "Available options:\n1. Add to queue.\n2. Delete from queue.\n3. Display queue\n0. Exit.\n\n";
    int choice;
    while (true)
    {
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the data to be entered: ";
            cin >> data;
            enqueue(queue, size, data);
            break;
        case 2:
            dequeue(queue, size);
            cout << "Queue top element removed!\n";
            break;
        case 3:
            display(queue, size);
            break;
        case 0:
            return 0;
            break;
        }
    }
}

void enqueue(float arr[], int size, float data)
{
    if (rear != size - 1)
    {
        if (front == -1)
            front++;
        arr[++rear] = data;
    }
    else
    {
        cout << "Cannot add further! Queue exhausted.\n";
    }
}

float dequeue(float arr[], int size)
{
    if (front != -1)
    {
        float temp = arr[front++];
        return temp;
    }
    else
        cout << "No element in the queue to be delted!\n";
    return -1;
}

void display(float arr[], int size)
{
    int i = front;
    while (i <= rear)
    {
        cout << arr[i] << ", ";
        i++;
    }
}