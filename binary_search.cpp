#include <iostream>
using namespace std;

int binary(float[], float, int, int);
void bubble(float[], int);
void printarr(float[], int);
void arrcopy(float[], float[], int);

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    float *arr = new float[size];
    float arr2[size];

    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    float num;
    cout << "Enter the number to be found in array: ";
    cin >> num;

    bubble(arr, size);
    arrcopy(arr, arr2, size);
    cout << "Sorted array is: ";
    printarr(arr2, size);

    int ind = binary(arr2, num, 0, size );
    if (ind == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index " << ind << endl;
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
                key = arr[j];
                arr[j] = arr[i];
                arr[i] = key;
            }
        }
    }
}

int binary(float arr[], float num, int low, int high)
{
    int mid;
    if (low >= high)
        return -1;
    else
    {
        mid = (low + high) / 2;
        if (arr[mid] == num)
            return mid;
        if (num > arr[mid])
            return binary(arr, num, mid + 1, high);
        else
            return binary(arr, num, low, mid - 1);
    }
}

void printarr(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

void arrcopy(float arr[], float arr2[], int size)
{
    for (int i = 0; i < size; i++)
        arr2[i] = arr[i];
    delete[] arr;
}