#include <iostream>
using namespace std;

void selction(float[], int);
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

    selction(arr, size);
    printarr(arr, size);
}

void selction(float arr[], int size)
{
    int key, j, i, temp;
    for (i = 0; i < size - 1; i++)
    {
        key = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[key])
                key = j;
        swap(arr[key],arr[i]);
    }
}

void printarr(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}