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

vector<int> corder(TreeNode *root)
{
    vector<int> a;
    stack<TreeNode *> s;

    if(!root)
        return a;

    TreeNode *p = root;

    while(!s.empty()||p)
    {
        while(p)
        {
            s.push(p);
            p = p->left;
        }

        p = s.top();
        s.pop();
        a.push_back(p->val);
        p = p->right;
    }

    return a;
}

void corder_recursion(TreeNode *root,vector<int> &a)
{
    if(!root)
        return;

    corder_recursion(root->left,a);
    a.push_back(root->val);
    corder_recursion(root->right,a);
}

int main()
{
    
    return 0;
}
