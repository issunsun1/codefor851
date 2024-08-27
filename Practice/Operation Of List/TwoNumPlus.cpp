// 两个用链表表示的数字相加
#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;

ListNode *PLUS(ListNode *l1, ListNode *l2)
{
    stack<int> s1;
    stack<int> s2;

    while(l1!=nullptr)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }

    while(l2!=nullptr)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int step = 0;
    ListNode *head;
    head->next = nullptr;

    while(!s1.empty()||!s2.empty()||step!=0)
    {
        int sum = step;

        if(!s1.empty())
        {
            sum += s1.top();
            s1.pop();
        }
        
        if(!s1.empty())
        {
            sum += s2.top();
            s2.pop();
        }

        ListNode *p;
        p->val = sum % 10;
        step = sum / 10;

        ListNode *temp = head->next;
        head->next = p;
        p->next = temp;
    }

    return head->next;
}
