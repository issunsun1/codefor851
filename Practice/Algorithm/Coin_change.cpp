#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    int maxn = 0x3f3f;
    int n = coins.size();
    vector< vector<int> > dp(n + 1, vector<int>(amount + 1, maxn));
    dp[0][0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j < amount + 1; j++)
        {
            if (j >= coins[i - 1])
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount] == maxn ? -1 : dp[n][amount];
}