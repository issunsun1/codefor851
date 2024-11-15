#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// 最优最坏平均时间复杂度 O(nlogn)
// 空间复杂度 O(1)
// 稳定排序算法

const int N = 100000;

void merge_sort(int a[N], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    int temp[N];
    int i = l, j = mid + 1, k = 0;

    while (i < mid + 1 && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];

    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = temp[j];
}

void merge_sort2(int a[N], int n)
{
    int temp[N];

    // 每次子数组的长度，从1开始倍增
    for (int size = 1; size < n; size *= 2)
    {
        // 从左到右合并子数组
        for (int left_start = 0; left_start < n; left_start += 2 * size)
        {
            int mid = min(left_start + size - 1, n - 1);
            int right_end = min(left_start + 2 * size - 1, n - 1);

            // 初始化指针
            int i = left_start, j = mid + 1, k = left_start;

            // 合并两个子数组
            while (i <= mid && j <= right_end)
            {
                if (a[i] <= a[j])
                {
                    temp[k++] = a[i++];
                }
                else
                {
                    temp[k++] = a[j++];
                }
            }

            // 拷贝剩余元素
            while (i <= mid)
            {
                temp[k++] = a[i++];
            }
            while (j <= right_end)
            {
                temp[k++] = a[j++];
            }

            // 拷贝回原数组
            for (i = left_start; i <= right_end; i++)
            {
                a[i] = temp[i];
            }
        }
    }
}

int main()
{
    int n;
    int a[N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
