#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define maxsize 1000

// 插入排序
// 时间复杂度
// 最优O(n) 平均复杂度O(n^2) 最差O(n^2)
// 空间复杂度O(1)
// 稳定排序算法

// 直接插入
void insertion_sort(int a[maxsize], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void binary_insertion_sort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int l = 0, h = i - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (a[i] < a[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }

        for (int j = i - 1; j >= h + 1; j--)
            a[j + 1] = a[j];
        a[h] = a[i];
    }
}

int main()
{

    return 0;
}
