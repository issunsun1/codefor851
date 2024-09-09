#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

void MinHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, n, smallest);
    }
}

void HeapSortMax(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}

void HeapSortMin(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        MinHeapify(arr, i, 0);
    }
}

int main()
{
    int arrMax[] = {12, 11, 13, 5, 6, 7};
    int nMax = sizeof(arrMax) / sizeof(arrMax[0]);

    HeapSortMax(arrMax, nMax);

    cout << "Sorted array (Max-Heap): \n";
    for (int i = 0; i < nMax; ++i)
        cout << arrMax[i] << " ";
    cout << endl;

    int arrMin[] = {12, 11, 13, 5, 6, 7};
    int nMin = sizeof(arrMin) / sizeof(arrMin[0]);

    HeapSortMin(arrMin, nMin);

    cout << "Sorted array (Min-Heap): \n";
    for (int i = 0; i < nMin; ++i)
        cout << arrMin[i] << " ";
    cout << endl;

    return 0;
}