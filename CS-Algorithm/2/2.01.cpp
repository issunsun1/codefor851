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
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(val), next(next) {};

}ListNode;

ListNode *delete_min(ListNode *head)
{
    if (head == nullptr)
        return head; // 空链表直接返回

    ListNode *dummy = new ListNode(-1, head);
    ListNode *p = dummy, *r = head;
    ListNode *min_pre = dummy;
    int min = INT_MAX;

    while (r != nullptr)
    {
        if (r->val < min)
        {
            min = r->val;
            min_pre = p;
        }
        p = p->next;
        r = r->next;
    }

    ListNode *temp = min_pre->next;
    min_pre->next = temp->next;
    delete temp;

    ListNode *new_head = dummy->next;
    delete dummy;
    return new_head;
}

int
main()
{
    
    return 0;
}
