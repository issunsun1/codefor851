#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 寻找链表中间结点
typedef struct ListNode{
    int val;
    ListNode *next;
} ListNode;

ListNode* middleNode(ListNode *head)
{

    if(head==nullptr)
        return nullptr;
    
    ListNode *p = head;
    ListNode *r = head;
    while(r!=nullptr&&r->next!=nullptr)
    {
        p = p->next;
        r = r->next->next;
    }

    return p;

}

int main()
{
    
    return 0;
}
