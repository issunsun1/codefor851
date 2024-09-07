#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 100000;

// 最优 平均时间复杂度 O(nlogn)
// 最坏时间复杂度 O(n^2)
// 空间复杂度 O(logn)
// 不稳定排序算法



void quick_sort(int a[N], int l, int r)
{
    if (l >= r)
        return;

    int i = l, j = r;
    int index = a[l];

    while (i < j)
    {
        if (a[i] < index)
            i++;
        if (a[j] > index)
            j--;
        if (i < j)
            swap(a[i], a[j]);
    }

    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main()
{
    int n;
    int a[N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
