// 移除重复结点
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
} ListNode;

ListNode * Remove(ListNode *head)
{
    ListNode *p = head;
    unordered_set<int> a;
    a.insert(p->val);
    while(p->next!=nullptr)
    {
        if(a.count(p->next->val))
            p->next = p->next->next;
        else
        {
            a.insert(p->next->val);
            p = p->next;
        }
    }

    return head;
}

int
main()
{
    
    return 0;
}
