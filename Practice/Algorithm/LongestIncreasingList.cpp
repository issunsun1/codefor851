#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 求最长连续递增子序列长度

int length(vector<int> nums)
{
    if(nums.empty())
        return 0;

    int maxlength = 1;
    int currentlength = 1;

    for (int i = 1; i < nums.size();i++)
    {
        if(nums[i]-nums[i-1]>0)
            currentlength++;
        else
            currentlength = 1;

        maxlength = max(currentlength, maxlength);
    }

    return maxlength;
}

int main()
{
    
    return 0;
}
