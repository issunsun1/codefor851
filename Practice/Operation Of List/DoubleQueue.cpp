#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class MyCircularDeque
{
public:
    int size;
    int front = 0;
    int rear = 0;
    vector<int> a;
    int length = 0;
    MyCircularDeque(int k)
    {
        size = k;
        a = vector<int>(k, 0);
        rear = k - 1;
    }

    bool insertFront(int value)
    {
        if (!isFull())
        {
            a[(front - 1 + size) % size] = value;
            front = (front - 1 + size) % size;
            length++;
            return true;
        }
        else
            return false;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        a[(rear + 1) % size] = value;
        rear = (rear + 1) % size;
        length++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        length--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (rear - 1 + size) % size;
        length--;
        return true;
    }

    int getFront()
    {
        return isEmpty() ? -1 : a[front];
    }

    int getRear()
    {
        return isEmpty() ? -1 : a[rear];
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
