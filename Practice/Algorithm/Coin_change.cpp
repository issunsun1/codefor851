#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector< vector<int> > dp(n + 1, vector<int>(amount + 1, INT_MAX));

        // 初始化：0金额需要0个硬币
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j]; // 不使用当前硬币
                if (j >= coins[i - 1])
                {
                    // 使用当前硬币
                    if (dp[i][j - coins[i - 1]] != INT_MAX)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                    }
                }
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount]; // 如果无法构成，则返回 -1
    }
};
