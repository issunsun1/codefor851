#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
// 生成nums数组的全排列
using namespace std;

vector< vector<int> > ans;

void backtrack(vector<int> &nums, int x, vector<int> &path)
{
    if (path.size() == nums.size())
    {
        ans.emplace_back(path);
        return;
    }

    for (int i = x; i < nums.size(); ++i)
    {
        swap(nums[x], nums[i]);
        path.emplace_back(nums[x]);
        backtrack(nums, x + 1, path);
        path.pop_back();
        swap(nums[x], nums[i]);
    }
}

vector< vector<int> > permute(vector<int> &nums)
{
    vector<int> path;
    backtrack(nums, 0, path);
    return ans;
}

