// 判断是否为回文链表，反转中间结点以后的链表，与头结点一一对比
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
} ListNode;

ListNode *reverse(ListNode *head)
{
    ListNode *p = nullptr;
    ListNode *r = head;

    while (r != nullptr)
    {
        ListNode *temp = r->next;
        r->next = p;
        p = r;
        r = temp;
    }

    return p;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *middle;
    ListNode *p = head;
    ListNode *q = head;
    ListNode *temp = nullptr;

    // 找到中间结点并截断
    while (q != nullptr && q->next != nullptr)
    {
        temp = p;
        p = p->next;
        q = q->next->next;
    }
    temp->next = nullptr;

    ListNode *head1 = head;
    ListNode *head2 = reverse(p);

    while (head1 != nullptr && head2 != nullptr)
        if (head1->val != head2->val)
            return false;
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    return true;
}



int main()
{
    
    return 0;
}
