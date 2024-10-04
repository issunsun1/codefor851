#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 1000;
// 最优最坏平均时间复杂度 O(n^2)
// 不稳定的排序算法
// 空间复杂度 O(1)
// 每次选择一个最小的放到数组头部

void select_sort(int a[N], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[min], a[i]);
    }
}

int main()
{

    return 0;
}
