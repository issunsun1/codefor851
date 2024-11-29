#include <iostream>
#include <vector>
using namespace std;

vector<int> weight;
vector<int> nums;
vector<int> value;

int resolve(int bagsize)
{
    int n = weight.size();
    int m = bagsize;


    vector< vector<int> > dp(n + 1, vector<int>(m+1));

    for (int i = 0; i < m + 1;i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m;j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k < nums[i - 1] && k * weight[i - 1] <= j;k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * weight[i - 1]]+k*value[i-1]);
            
        }

    return dp[n][m];
}

int solve2(int bagsize)
{
    int n = weight.size();
    int m = bagsize;

    vector< vector<int> > dp(n + 1, vector<int>(m + 1));

    dp[0][0] = 0;
    for (int i = 0; i <= n;i++)
    {
        dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
        {
            if(weight[i-1]<=j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][m];
}

int calculate(vector<int> a)
{
    int sum = 0;
    int maxn = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum = max(sum, 0) + nums[i];
        maxn = max(maxn, sum);
    }

    return maxn;
}

int coinchange(vector<int> coins,int amount)
{
    int maxn = 0x3f3f3f;
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, maxn));

    dp[0][0];

    for (int i = 1; i <= n;i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= n;j++)
        {
            if(j>=coins[i-1])
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - coins[i - 1]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount] == maxn ? -1 : dp[n][amount];
}