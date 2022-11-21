#include <iostream>
using namespace std;

void insertion(float[], int);
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

    insertion(arr, size);
    printarr(arr, size);
}

void insertion(float arr[], int size)
{
    int key, j;
    for (int i = 0; i < size; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && key <= arr[j])
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

void printarr(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}