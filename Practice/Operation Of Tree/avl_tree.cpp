#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef int datatype;

typedef struct avlnode
{
    datatype data;
    int height;
    avlnode *left;
    avlnode *right;
} avlnode, *avltree;

avlnode *init_node(datatype data, avlnode *left, avlnode *right)
{
    avlnode *p = (avlnode *)malloc(sizeof(avlnode));

    p->data = data;
    p->height = 0;
    p->left = left;
    p->right = right;

    return p;
}

int hight(avlnode *root)
{
    if (root == nullptr)
        return 0;
    return max(hight(root->left), hight(root->right)) + 1;
}

// LL
avlnode *ll_rotation(avltree k1)
{
    avltree k2;

    k2 = k1->left;
    k1->left = k2->right;
    k2->left = k1;

    k2->height = hight(k2);
    k1->height = hight(k1);

    return k2;
}

// RR
avlnode *rr_rotation(avltree k1)
{
    avltree k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k2->height = hight(k2);
    k1->height = hight(k1);
}

avlnode *lr_rotation(avltree k3)
{
    k3->left = rr_rotation(k3->left);
    return ll_rotation(k3);
}

avlnode *rl_rotation(avltree k3)
{
    k3->right = ll_rotation(k3->right);
    return ll_rotation(k3);
}

int main()
{

    return 0;
}
