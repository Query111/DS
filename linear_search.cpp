#include <iostream>
using namespace std;

int linear(float[], float, int);

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
    float num;
    cout << "Enter the number to be found in array: ";
    cin >> num;

    int ind = linear(arr, num, size);
    if (ind == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index " << ind << endl;
}

int linear(float arr[], float num, int size){
    for(int i=0;i<size;i++)
        if(arr[i]==num)
            return i;
    return -1;
}