#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int s, y, n;
    cin >> s >> y >> n;
    vector<int> invest(n);
    vector<int> index(n);

    for (int i = 0; i < n;i++)
        cin >> invest[i] >> index[i];

    vector< vector<int> > dp(n + 1, vector<int>(y + 1, 0));

    for (int i = 1; i < n + 1;i++)
        for (int j = 1; j < y + 1;j++)
        {
            dp[i][j] = d[i][j - 1];
            if (j)
        }

    return 0;
}
