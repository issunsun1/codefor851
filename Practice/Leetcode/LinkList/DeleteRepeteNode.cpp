//   删除链表中重复出现的结点，包括其本身
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val,ListNode *next)
    {
        this->val = val;
        this->next = next;
    };
}ListNode;

void deletenode(ListNode *head)
{
    if(head == nullptr)
        return;

    ListNode *dummy = new ListNode(-1, head);
    ListNode *p = dummy;
    ListNode *r = head;

    while(r!=nullptr)
    {
        if(r->next!=nullptr&&r->val==r->next->val)
        {
            while(r->next!=nullptr&&r->val==r->next->val)
                r = r->next;
            p->next = r->next;
        }
        else
        {
            p = p->next;
        }
        r = r->next;
    }

    head = dummy->next;
    delete dummy;
}

int
main()
{
    

    return 0;
}
