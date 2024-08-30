#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;


class Solution
{
private:
    void searchBST(TreeNode *cur, unordered_map<int, int> &map)
    { // 前序遍历
        if (cur == NULL)
            return;
        map[cur->val]++; // 统计元素频率
        searchBST(cur->left, map);
        searchBST(cur->right, map);
        return;
    }
    bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> map;
        vector<int> result;
        if (root == NULL)
            return result;
        searchBST(root, map);
        vector< pair<int, int> > vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp); // 给频率排个序
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].second == vec[0].second)
                result.push_back(vec[i].first);
            else
                break;
        }
        return result;
    }
};

int main()
{
    
    return 0;
}
