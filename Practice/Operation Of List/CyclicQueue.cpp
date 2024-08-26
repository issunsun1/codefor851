#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class MyCircularQueue
{
public:
    int size = 0;
    int front = 0;
    int rear = 0;
    int length = 0;
    vector<int> a;

    MyCircularQueue(int k)
    {
        size = k;
        a = vector<int>(k, 0);
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        a[rear % size] = value;
        rear = (rear + 1) % size;
        length++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        length--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return a[front % size];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return a[(rear - 1 + size) % size]; // 这里需要加 size，确保不会出现负数取模的情况
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == size;
    }
};

int main()
{
    
    return 0;
}
