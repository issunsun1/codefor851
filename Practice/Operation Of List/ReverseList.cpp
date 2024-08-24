// 反转链表
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
}ListNode;

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

int main()
{
    
    return 0;
}
