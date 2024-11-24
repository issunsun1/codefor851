#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 10010;
vector<int> value;
vector<int> weight;
int bagsize;

// 01背包问题(二维数组)

int resolution()
{
    int m = weight.size(); // 物品数量
    int n = bagsize + 1;   // 背包容量 + 1

    vector< vector<int> > a(m + 1, vector<int>(n, 0)); // 创建二维数组，初始化为0

    // 填充动态规划数组
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= bagsize; j++)
        {
            if (j < weight[i - 1])     // 如果背包容量小于当前物品的重量，不能放入该物品
                a[i][j] = a[i - 1][j]; // 继承前一行的最大值
            else
                // 选择放入或不放入当前物品，取最大值
                a[i][j] = max(a[i - 1][j], a[i - 1][j - weight[i - 1]] + value[i - 1]);
        }
    }

    return a[m][bagsize]; // 返回背包容量为 bagsize 时的最大价值
}

int main()
{
    return 0;
}