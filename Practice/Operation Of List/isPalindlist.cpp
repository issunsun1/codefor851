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


// 找到并返回中间结点
ListNode* middleNode(Listnode *head)
{
    ListNode *p = head;
    ListNode *r = head;
    while(r!=nullptr&&r->next!=nullptr)
    {
        p = p->next;
        r = r->next->next;
    }
    return p;
}

// 反转链表
ListNode* reverseList(ListNode *head)
{
    ListNode *p = nullptr;
    ListNode *r = head;
    while(r!=nullptr)
    {
        ListNode *temp = r->next;
        r->next = p;
        p = r;
        r = temp;
    }

    return p;
}

bool ispalindList(ListNode *head)
{
    ListNode *middleNode = middleNode(head);
    ListNode *head2 = reverseList(middleNode);

    while(head!=nullptr&&head2!=nullptr)
    {
        if(head->val!=head2->val)
            return false;

        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int main()
{
    
    return 0;
}
