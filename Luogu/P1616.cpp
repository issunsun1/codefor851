#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int t, n;
    cin >> t >> n;
    vector<int> time(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++)
        cin >> time[i] >> value[i];

    vector< vector<int> > dp(n + 1, vector<int>(t + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j]; // 不选第 i 种草药
            if (j >= time[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i][j - time[i - 1]] + value[i - 1]);
            }
        }
    }

    cout << dp[n][t] << endl;

    return 0;
}
