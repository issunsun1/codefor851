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
    ListNode(int x, ListNode *n) : val(x), next(n) {};
} ListNode;

ListNode * reverse(ListNode * &head)
{
    ListNode *p = nullptr, *r = head;
    while(r!=nullptr)
    {
        ListNode *temp = r->next;
        r->next = p;
        p = r;
        r = temp;
    }
    return p;
}

bool judege(ListNode *head)
{
    ListNode *p = head, *r = head;
    while (r != nullptr && r->next != nullptr)
    {
        p = p->next;
        r = r->next->next;
    }

    ListNode *half = p->next;
    p->next = nullptr;

    ListNode *m = head, *n = half;
    while(m!=nullptr&&n!=nullptr)
    {
        if(m->val!=n->val)
            return false;
        else
        {
            m = m->next;
            n = n->next;
        }
    }

    return true;
}

int
main()
{
    
    return 0;
}
