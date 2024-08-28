#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> coins;

int coinChangeDP(int sum)
{
    vector<vector<int>> a(coins.size(), vector<int>(sum + 1, 0));

    int m = coins.size();
    int n = sum + 1;

    int maxn = sum + 1;

    // 初始化 dp 表
    // 状态转移：首行首列
    for (int i = 1; i < n; i++)
        a[0][i] = maxn;

    // 状态转移：其余行和列
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            if (coins[i] > j)
            {
                // 若超过目标金额，则不选硬币 i
                a[i][j] = a[i - 1][j];
            }
            else
            {
                // 不选和选硬币 i 这两种方案的较小值
                a[i][j] = min(a[i - 1][j], a[i][j - coins[i]] + 1);
            }
        }

    return a[m - 1][n - 1] != maxn ? a[m - 1][n - 1] : -1;
}
