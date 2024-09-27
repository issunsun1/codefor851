#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 10000;

typedef struct huffmannode
{
    int val;
    huffmannode *lchild;
    huffmannode *rchild;
} huffmannode, *huffmanTree;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){};
} TreeNode;


int main()
{

    return 0;
}
