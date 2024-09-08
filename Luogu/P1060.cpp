#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> price(m + 1, 0);
    vector<int> impce(m + 1, 0);

    for (int i = 1; i <= m; i++)
        cin >> price[i] >> impce[i];

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= price[i]; j--)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i]] + price[i] * impce[i]);
        }
        for (int j = price[i] - 1; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}
