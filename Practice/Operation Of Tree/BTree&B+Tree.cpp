#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int n;

typedef struct BTreeNode
{
    vector<int> keys;
    vector<BTreeNode *> children;
    bool isLeaf;

    BTreeNode(bool leaf) : isLeaf(leaf) {}
}BTreeNode;

BTreeNode search(int k)
{
    int i = 0;
    // 找到第一个大于等于待查找键k的键
    while(i<n&&k>keys[i])
        i++;
    
    // 如果找到的第一个键等于k，返回节点指针
    if(keys[i]==k)
        return this;

    // 如果没有找到键k且当前节点为叶子节点则返回NULL
    if(leaf==true)
        reutrn NULL;

    // 递归
    return children[i]->search(k);
}

int
main()
{
    
    return 0;
}
