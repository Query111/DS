#include <iostream>
using namespace std;

void merge(float[], int, int, int);
void printarr(float[], int);
void mergesort(float[], int, int);

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    float arr[size];

    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    mergesort(arr, 0, size - 1);
    printarr(arr, size);
}

void printarr(float arr[], int size)
{
    cout << "Sorted array is: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

void merge(float arr[], int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    auto *left = new float[n1], *right = new float[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + j + 1];
    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void mergesort(float arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}