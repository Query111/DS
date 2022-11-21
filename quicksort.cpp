#include <iostream>
using namespace std;

void quick(float[], int, int);
void printarr(float[], int);

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    float arr[size];

    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    quick(arr, 0, size - 1);
    printarr(arr, size);
}

void quick(float arr[], int first, int last)
{

    int lower = first + 1, upper = last;
    swap(arr[first], arr[(first + last) / 2]);
    float bound = arr[first];

    while (lower <= upper)
    {
        while (bound > arr[lower])
            lower++;
        while (bound < arr[upper])
            upper--;
        if (lower < upper)
            swap(arr[lower++], arr[upper--]);
    }

    swap(arr[upper], arr[first]);
    if (first >= last)
        return;
    if (first < upper - 1)
        quick(arr, first, upper - 1);
    if (upper + 1 < last)
        quick(arr, upper++, last);
}

void printarr(float arr[], int size)
{
    cout<<"Sorted array is: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}
