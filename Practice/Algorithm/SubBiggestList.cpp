#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int calculate(vector<int> nums)
{
    int maxn = 0;
    int minn = 0;
    int ans = 0;

    for (int i = 0; i < nums.size();i++)
    {
        maxn = max(nums[i], 0) + maxn;
        minn = min(nums[i], 0) + minn;
        ans = max(ans, max(maxn, abs(minn)));
    }

    return ans;
}

int main()
{
    
    return 0;
}
