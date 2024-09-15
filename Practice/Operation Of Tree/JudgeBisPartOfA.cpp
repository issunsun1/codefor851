#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 判断B树是否是A树的一部分

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

bool isSubstructrue(TreeNode *A, TreeNode *B)
{
    if (A == nullptr && B == nullptr)
        return true;
    if (A == nullptr || B == nullptr || A->val != B->val)
        return false;
    return isSubstructrue(A->left, B->left) && isSubstructrue(A->right, B->right);
}

bool judgement(TreeNode *A,TreeNode *B)
{
    // 当B为空树时，始终为A的子树
    if(B==nullptr)
        return true;
    // 如果A为空树且B不为空树，则返回false
    if(A==nullptr)
        return false;
    // 递归判断A树及其左右子树是否存在与B树相同的结构
    return isSubstructrue(A, B) || isSubstructrue(A->left, B) || isSubstructrue(A->right, B);
}



int main()
{
    
    return 0;
}
