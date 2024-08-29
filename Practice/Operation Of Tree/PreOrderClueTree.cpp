#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct TBNode{
    int val;
    int ltag;
    int rtag;
    TBNode *left;
    TBNode *right;
} TBNode;

void PreOrderTree(TBNode *root,TBNode *pre)
{
    if(!root)
        return;

    if(!root->left)
    {
        root->left = pre;
        root->ltag = 1;
    }

    if(root&&!pre->right)
    {
        pre->right = root;
        pre->rtag = 1;
    }

    pre = root;

    if(!root->ltag)
        PreOrderTree(root->left, pre);
    if(!root->rtag)
        PreOrderTree(root->right, pre);
}

int main()
    {

        return 0;
}
