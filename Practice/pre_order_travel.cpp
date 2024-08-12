#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef int datatype;

typedef struct trenode
{
    datatype data;
    trenode *left;
    trenode *right;
} trenode, *tree;

void pre_order_no_recursion(tree a)
{
    stack<trenode *> s;
    trenode *t = a;
    while (t || !s.empty())
    {
        while (t)
        {
            cout << t->data;
            s.push(t);
            t = t->left;
        }
        t = s.top();
        s.pop();
        t = t->right;
    }
}

void pre_order_recursion(tree a)
{
    if (a == NULL)
        return;

    cout << a->data;

    pre_order_recursion(a->left);
    pre_order_recursion(a->right);
}

int main()
{

    return 0;
}
