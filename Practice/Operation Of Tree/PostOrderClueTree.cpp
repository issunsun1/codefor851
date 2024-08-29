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
    int ltag = 0;
    int rtag = 0;

    TBNode *left;
    TBNode *right;
} TBNode;

void BuildPostOrderClueTree(TBNode *root, TBNode *&pre)
{
    if (!root)
        return;

    BuildPostOrderClueTree(root->left, pre);
    BuildPostOrderClueTree(root->right, pre);

    if (!root->left)
    {
        root->left = pre;
        root->ltag = 1; // Mark as thread
    }
    if (pre && !pre->right)
    {
        pre->right = root;
        pre->rtag = 1; // Mark as thread
    }

    pre = root;
}

int
main()
{
    
    return 0;
}
