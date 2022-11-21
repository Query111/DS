#include <iostream>
using namespace std;

void bubble(float[], int);
void printarr(float[], int);

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    float arr[size];

    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    bubble(arr, size);
    printarr(arr, size);
}

void bubble(float arr[], int size)
{
    int key, j, i;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}

void printarr(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}