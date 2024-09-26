#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
// 利用哈希集合删除重复出现的结点

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr) {};
} ListNode;

ListNode *deleteNode(ListNode *head)
{
    unordered_set<ListNode *> set;
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy, *r = head;
    while(r!=nullptr)
    {
        if(set.count(r))
            p->next = r->next;
        else
        {
            p = r;
            set.insert(r);
        }
        r = r->next;
    }

    return dummy->next;
}

int main()
{
    
    return 0;
}
