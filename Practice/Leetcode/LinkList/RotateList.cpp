// 旋转链表，将每个节点向右移动k个位置
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
    ListNode(int val,ListNode *next){
        this->val = val;
        this->next = next;
    };
}ListNode;


void rotate_list(ListNode * &head,int k)
{
    int listlength = 0;
    ListNode *temp = head;

    while(head!=nullptr)
    {
        listlength++;
        head = head->next;
    }
    if(k%listlength==0)
        return;

    delete temp;

    ListNode *p = head;
    ListNode *r = head;

    for (int i = 0; i < k;i++)
        r = r->next;
    while(r->next!=nullptr)
    {
        p = p->next;
        r = r->next;
    }

    ListNode *new_head = p->next;
    p->next = nullptr;
    r->next = head;

    head = new_head;
}

int main()
{
    
    return 0;
}
