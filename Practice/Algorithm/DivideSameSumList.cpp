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
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        for (int x : nums)
            sum += x;
        if (sum % 2)
            return false;
        int m = sum / 2;
        vector< vector<bool> > f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j >= nums[i - 1])
                    f[i][j] = f[i - 1][j - nums[i - 1]] | f[i - 1][j];
                else
                    f[i][j] = f[i - 1][j];
            }
        }
        return f[n][m];
    }
};
