#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef int datatype;

typedef struct node
{
    datatype data;
    node *left;
    node *right;
} node, *tree;

void center_order_no_recursion(tree root)
{
    stack<node *> s;

    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->data;
        root = root->right;
    }
}

void center_order_recursion(tree root)
{
    if (root == NULL)
        return;

    center_order_recursion(root->left);
    cout << root->data;
    center_order_recursion(root->right);
}

int main()
{

    return 0;
}
