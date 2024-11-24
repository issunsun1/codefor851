#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> weight;
vector<int> value;
vector<int> nums;
int bagsize;

// 多重背包问题


int resolution() {
    int n = weight.size();  // 物品数量
    vector< vector<int> > dp(n + 1, vector<int>(bagsize + 1, 0));  // 动态规划表

    // 初始化第一行的状态
    for (int i = 0; i <= bagsize; i++) {
        dp[0][i] = 0;  // 物品0的情况（没有物品，价值为0）
    }

    // 从第1个物品开始
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= bagsize; j++) {
            dp[i][j] = dp[i - 1][j];  // 不选当前物品时的最大值

            // 尝试选当前物品的不同数量
            for (int k = 1; k <= nums[i - 1] && k * weight[i - 1] <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * weight[i - 1]] + k * value[i - 1]);
            }
        }
    }

    // 返回最大价值
    return dp[n][bagsize];
}

int main()
{
}