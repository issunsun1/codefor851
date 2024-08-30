#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
public:
    MaxHeap(vector<int> &nums) : heap(nums)
    {
        buildHeap();
    }

    void heapify(int i, int heapSize)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && heap[left] > heap[largest])
            largest = left;

        if (right < heapSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest, heapSize);
        }
    }

    void buildHeap()
    {
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            heapify(i, heap.size());
        }
    }

    void heapSort()
    {
        buildHeap();
        for (int i = heap.size() - 1; i > 0; --i)
        {
            swap(heap[0], heap[i]);
            heapify(0, i);
        }
    }

    void printHeap() const
    {
        for (int num : heap)
        {
            cout << num << " ";
        }
        cout << endl;
    }

private:
    vector<int> heap;
};

int main()
{
    // vector<int> nums = {4, 10, 3, 5, 1};
    vector<int> nums;
    
    MaxHeap maxHeap(nums);
    cout << "Before Heap Sort: ";
    maxHeap.printHeap();

    maxHeap.heapSort();
    cout << "After Heap Sort: ";
    maxHeap.printHeap();

    return 0;
}
