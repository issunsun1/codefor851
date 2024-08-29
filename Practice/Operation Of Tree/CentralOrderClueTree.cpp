#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct TBNode
{
    int val;
    int ltag;
    int rtag;
    TBNode *left;
    TBNode *right;
} TBNode;

void BuildClueTree(TBNode *root,TBNode *pre)
{
    if(!root)
        return;

    if(root)
        BuildClueTree(root->left,pre);

    if(!root->left)
    {
        root->left = pre;
        root->ltag = 1;
    }
    if(pre&&!pre->right)
    {
        pre->right = root;
        pre->rtag = 1;
    }

    pre = root;

    BuildClueTree(root->right, pre);
}

int
main()
{
    
    return 0;
}
