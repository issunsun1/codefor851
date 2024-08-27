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

ListNode *mergesort(ListNode *head1, ListNode *head2)
{
    // 新建头结点dummy 用于存放head1与head2归并排序后的结果
    ListNode *dummy;
    dummy->next = nullptr;
    ListNode *p = dummy;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->val < head2->val)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }

    p->next = head1 == nullptr ? head2 : head1;
    return dummy->next;
}

ListNode *middlenode(ListNode *head)
{
    ListNode *p = head;
    ListNode *r = head;
    while (r != nullptr && r->next != nullptr)
    {
        p = p->next;
        r = r->next->next;
    }
    return p;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    // ListNode *p = head;
    // ListNode *r = head;
    // ListNode *pre = nullptr;
    // while (r != nullptr && r->next != nullptr)
    // {
    //     pre = p;
    //     p = p->next;
    //     r = r->next->next;
    // }
    // pre->next = nullptr;


    ListNode *head1 = head;
    ListNode *head2 = middlenode(head);

    head1 = sortList(head1);
    head2 = sortList(head2);
    return mergesort(head1, head2);
}


int
main()
{
    
    return 0;
}
