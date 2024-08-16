#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef int datatype;

typedef struct tnode
{
    datatype data;
    tnode *left;
    tnode *right;
} tnode, *tree;

void back_order_no_recursion(tree root)
{
    stack<tnode *> s;
    tnode *last = NULL;
    while (root)
    {
        while (root || !s.empty())
            ;
        {
            s.push(root);
        }

        root = s.top();
        s.pop();

        // 如果当前节点无右子树或者右子树根节点为上一个访问过的节点
        if (!root->right || root->right == last)
        {
            cout << root->data;
            last = root; // 记录当前访问过的节点
            root = NULL;
        }
        else
        {
            s.push(root);       // 否则将当前节点重新入栈
            root = root->right; // 转而前往其右子树
        }
    }
}

void back_order_recursion(tree root)
{
    if (root == NULL)
        return;

    back_order_recursion(root->left);
    back_order_recursion(root->right);
    cout << root->data;
}

int main()
{
    cout << 'success' << endl;
    return 0;
}