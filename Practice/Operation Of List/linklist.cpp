#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 链表结构体定义
typedef struct linklist
{
    int data;
    struct linklist *pre, *next;
} linklist;

// 初始化头节点
linklist *init_linklist()
{
    linklist *node;
    node = (linklist *)malloc(sizeof(linklist));
    // cout << "success" << endl;
    return node;
}

// 在链表中添加元素
void add_linklist(linklist *L, int data)
{
    linklist *node = (linklist *)malloc(sizeof(linklist));
    node->data = data;
    while (L->next != NULL)
        L = L->next;
    L->next = node;
    // cout << "add success" << endl;
    // cout << L->data << endl;
}

// 在链表的第i个位置插入新的节点
void insert_linklist(linklist *L, int i, int data)
{
    int count = 0;
    linklist *node = (linklist *)malloc(sizeof(linklist));
    node->data = data;
    while (count++ != i - 1)
        L = L->next;
    node->next = L->next;
    L->next = node;
    // cout << "insert success" << endl;
}

// 删除链表第i个位置的节点
void delete_linklist(linklist *L, int i)
{
    int count = 0;
    while (count++ != i - 1)
        L = L->next;
    linklist *temp = L->next;
    L->next = L->next->next;
    free(temp);
}

// 输出链表中所有数
void display_linklist(linklist *L)
{
    linklist *l = L->next;
    while (l != NULL)
    {
        cout << l->data << " ";
        l = l->next;
    }
    cout << endl;
}

// 按值查找
int search_linklist(linklist *L, int data)
{
    int i = 1;
    linklist *l = L->next;
    while (l->data != data)
        i++;
    return i;
}

int main()
{
    // cout << "success test" << endl;
    linklist *L;
    L = init_linklist();
    add_linklist(L, 4);
    add_linklist(L, 2);
    add_linklist(L, 1);
    add_linklist(L, 3);
    add_linklist(L, 6);
    add_linklist(L, 7);
    display_linklist(L);
    // insert_linklist(L, 1, 5);
    // cout << L->next->data << endl;
    return 0;
}
