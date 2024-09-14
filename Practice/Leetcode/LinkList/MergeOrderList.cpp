#include <iostream>
#include <algorithm>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
}ListNode;

// 合并两个有序链表

ListNode *merge(ListNode *l1,ListNode *l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
        
    ListNode *dummy = new ListNode(), *p = dummy;

    while(l1!=nullptr&&l2!=nullptr)
    {
        if(l1->val<l2->val)
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
    }

    p->next = l1 == nullptr ? l2 : l1;

    return dummy->next;
}