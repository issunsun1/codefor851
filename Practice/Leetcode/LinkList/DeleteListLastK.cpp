// 删除链表的倒数第N个结点
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
    ListNode(int val, ListNode *next) {
        this->val = val;
        this->next = next;
    };
} ListNode;

void delete_node(ListNode* &head,int k)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *p = dummy;
    ListNode *r = head;
    for (int i = 0; i < k; i++)
        if(r!=nullptr)
            r = r->next;
        else
        // 链表长度不足k 函数返回
        {
            delete dummy;
            return;
        }

    while(r != nullptr)
    {
        p = p->next;
        r = r->next;
    }

    ListNode *temp = p->next;
    p->next = temp->next;

    delete temp;

    head = dummy->next;
    delete dummy;
}

int
main()
{

    
    return 0;
}
