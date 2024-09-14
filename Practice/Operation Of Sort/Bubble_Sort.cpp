#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
const int N = 1000;

// 最优时间复杂度 O(n)
// 最坏时间复杂度 O(n^2)
// 平均时间复杂度 O(n^2)
// 是一种稳定的排序算法

// 排序过程：每次确定一个最大的元素放在数组结尾

void bubble_sort(int a[N], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);

}

void bubble(vector<int> a)
{
    for (int i = 0; i < a.size() - 1;i++)
        for (int j = 0; j < a.size() - 1 - i;j++)
                if(a[j]>a[j+1])
                    swap(a[j], a[j + 1]);
}

int main()
{

    return 0;
}
