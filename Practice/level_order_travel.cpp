#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef int datatype;

typedef struct tnode
{
    datatype data;
    tnode *left;
    tnode *right;
} tnode, *tree;

void leveltravel(tree root)
{
    queue<tnode *> s;
    s.push(root);

    while (!s.empty())
    {
        tnode *p = s.front();
        cout << p->data;
        if (p->left != NULL)
            s.push(p->left);
        if (p->right != NULL)
            s.push(p->right);
    }
}

int main()
{

    return 0;
}
