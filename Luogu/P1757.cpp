#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    vector<int> weight(n);
    vector<int> value(n);
    vector<int> group(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i] >> group[i];

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
        {
            if(j>weight[i])
            {
                if(group[i-1]==group[i])
                    dp[i][j] = max(dp[i - 1][j - weight[i]], dp[i][j - 1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }

    return dp[n - 1][m - 1];
}