#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 判断链表中是否存在环

typedef struct ListNode
{
    int val;
    ListNode *next;
} Listnode;

unordered_set<Listnode *> a;

bool resolution(Listnode *root)
{
    if(root==nullptr)
        return false;
    ListNode *p = root;
    while(p!=nullptr)
    {
        if(a.count(p))
            return true;
        else
            a.insert(p);
        p = p->next;
    }

    return false;
}

// 使用双指针判断链表中是否存在环
bool judge(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return true;
    }

    return false;
}