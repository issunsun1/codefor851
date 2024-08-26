#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

typedef struct ListNode
{
    int val;
    ListNode *next;
}ListNode;

TreeNode *List2Tree(ListNode *head)
{
    if(head==nullptr)
        return nullptr;

    ListNode *p = head;
    ListNode *r = head;
    ListNode *pre = nullptr;

    while(r!=nullptr&&r->next!=nullptr)
    {
        pre = p;
        p = p->next;
        r = r->next->next;
    }

    pre->next = nullptr;

    TreeNode *root = new TreeNode(p->val);
    root->left = List2Tree(head);
    root->right = List2Tree(p->next);
}