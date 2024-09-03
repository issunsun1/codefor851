#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct BTNode
{
    int val;
    int rtag;
    int ltag;
    BTNode *left;
    BTNode *right;
} BTNode;

BTNode *pre = nullptr;

void cen(BTNode *root)
{
    if(root)
    {
        cen(root->left);
        if(!root->left)
        {
            root->left = pre;
            root->ltag = 1;
        }
        else root->ltag = 0;
        if(!root->right)
        {
            root->rtag = 1;
        }
        else
            root->rtag = 0;
        if(pre)
        {
            if(pre->rtag==1)
                pre->right = pre;
            if(pre->ltag==1)
                
        }

        pre = root;
        cen(root->right);
    }
}

int
main()
{
    
    return 0;
}
