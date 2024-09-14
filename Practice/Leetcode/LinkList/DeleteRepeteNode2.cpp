// 删除重复出现的多余结点，不包括重复出现的结点本身
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
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    };
} ListNode;

void deletenode(ListNode *head)
{
    if(head==nullptr)
        return;

    // ListNode *dummy = new ListNode(-1, head);
    ListNode *p = head;

    while (p->next)
    {
        ListNode *temp = p->next->next;
        if (p->next->val == p->val)
            p->next = temp;
        else
            p = p->next;
    }

}

int main()
{
    
    return 0;
}
