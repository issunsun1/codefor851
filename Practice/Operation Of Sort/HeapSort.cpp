#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
const int N = 100010;
int h[N], size;

void down(vector<int> &a, int start, int end)
{
    // 计算父结点和子结点的下标
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end)
    { // 子结点下标在范围内才做比较
        // 先比较两个子结点大小，选择最大的
        if (child + 1 <= end && a[child] < a[child + 1])
            child++;
        // 如果父结点比子结点大，代表调整完毕，直接跳出函数
        if (a[parent] >= a[child])
            return;
        else
        { // 否则交换父子内容，子结点再和孙结点比较
            swap(a[parent], a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

void heap_sort(vector<int> arr, int len)
{
    // 从最后一个节点的父节点开始 sift down 以完成堆化 (heapify)
    for (int i = arr.size() / 2; i >= 0; i--)
        down(arr, i, arr.size() - 1);
    // 先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕
    for (int i = arr.size() - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        down(arr, 0, i - 1);
    }
}

int main()
{

    return 0;
}
