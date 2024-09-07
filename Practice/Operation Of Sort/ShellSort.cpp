#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 平均时间复杂度 O(n(logn)^2)
// 最差时间复杂度 O(n(logn)^2)
// 最优时间复杂度 O(n)
// 空间复杂度 O(1)
// 不稳定排序算法

vector<int> shellsort(vector<int> &a)
{
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
    return a;
}

int main()
{
    
    return 0;
}
