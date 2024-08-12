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

// LL
avlnode *ll_rotation(avltree m)
{
    avltree n;

    n = m->left;
    m->left = n->right;
    n->right = m;
}

int main()
{

    return 0;
}
