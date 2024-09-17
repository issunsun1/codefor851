#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 求最长递增子序列长度

int length(vector<int> nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> dp(nums.size(), 1);
    int maxn = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxn = max(maxn, dp[i]);
    }

    return maxn;
}

int main()
{
    
    return 0;
}
