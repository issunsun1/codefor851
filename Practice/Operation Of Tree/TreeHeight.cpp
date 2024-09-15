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
}TreeNode;

int height(TreeNode *root)
{
    if(root==nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    
    return 0;
}
