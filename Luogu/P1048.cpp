#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int time, num;
    cin >> time >> num;
    vector<int> needtime(num);
    vector<int> value(num);
    for (int i = 0; i < num; i++)
        cin >> needtime[i] >> value[i];

    vector<vector<int>> dp(num + 1, vector<int>(time + 1, 0));

    // 处理每个物品
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j <= time; j++)
        {
            if (j >= needtime[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - needtime[i - 1]] + value[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // 输出最大价值
    cout << dp[num][time] << endl;

    return 0;
}
