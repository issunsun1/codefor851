#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector <vector<int> > res;
vector<int> path;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

void recur(TreeNode *root, int tar, vector< vector<int> > & res)
{
    if (root == nullptr)
        return;
    path.push_back(root->val);
    tar -= root->val;
    if (tar == 0 && root->left == nullptr && root->right == nullptr)
        res.push_back(path);
    recur(root->left, tar,res);
    recur(root->right, tar,res);
    path.pop_back();
}

vector <vector<int> > pathsearch(TreeNode *root, int target)
{
    vector< vector<int> > res;
    recur(root, target,res);
    return res;
}



int main()
{
    
    return 0;
}

