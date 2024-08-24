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
} ListNode;

int returnnum(ListNode *head,int k)
{
    ListNode *p = head;
    ListNode *r = head;

    while(k--)
        r = r->next;

    while(r!=nullptr)
    {
        p = p->next;
        r = r->next;
    }

    return p->val;
}

int
main()
{
    
    return 0;
}
