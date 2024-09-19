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

    // 判断当前结点的左子树是否可以先序线索化
    if(!root->left)
    {
        root->left = pre;
        root->ltag = 1;
    }

    // 判断上个结点的右子树是否可以后序线索化
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
