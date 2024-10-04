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
    vector< vector<int> > permute(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }

private:
    vector< vector<int> > res;
    void dfs(vector<int> &nums, int x)
    {
        if (x == nums.size() - 1)
        {
            res.push_back(nums); // 添加排列方案
            return;
        }
        for (int i = x; i < nums.size(); i++)
        {
            swap(nums[i], nums[x]); // 交换，将 nums[i] 固定在第 x 位
            dfs(nums, x + 1);       // 开启固定第 x + 1 位元素
            swap(nums[i], nums[x]); // 恢复交换
        }
    }
};