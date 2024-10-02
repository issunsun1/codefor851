#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> path;
vector< vector<int> > ans;

void dfs(vector<int> &nums, int index)
{
    if (index == nums.size())
    {                        // 找到了一组子集
        ans.push_back(path); // 放入需要返回的数组
        return;
    }
    // 选index处的元素
    path.push_back(nums[index]);
    dfs(nums, index + 1); // 已经放入了index,所以新的搜索位置是index+1
    path.pop_back();      // 回溯
    // 不选index处的元素,那么直接从index+1的位置开始搜索
    dfs(nums, index + 1);
}
vector< vector<int> > subsets(vector<int> &nums)
{
    dfs(nums, 0); // 从下标为0的位置开始搜索
    return ans;
}
