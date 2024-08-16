#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct linklist
{
    char data;
    linklist *prior;
    linklist *next;
} linklist;

// 头插法建立单链表
linklist *head_buildlist()
{
    char input;
    linklist *head = (linklist *)malloc(sizeof(linklist));
    head->data = 0;
    head->next = NULL;
    while ((input = getchar()) != '#')
    {
        linklist *node = (linklist *)malloc(sizeof(linklist));
        node->data = input;
        node->next = head->next;
        head->next = node;
    }
    // cout << "success build" << endl;

    return head;
}

// 尾插法建立单链表
linklist *tail_buildlist()
{
    int input;
    linklist *head = (linklist *)malloc(sizeof(linklist));
    head->data = 0;
    head->next = NULL;
    linklist *temp = head;
    while (scanf("%d", &input) != EOF)
    {
        while (temp->next != NULL)
            temp = temp->next;
        linklist *node = (linklist *)malloc(sizeof(linklist));
        node->data = input;
        node->next = temp->next;
        temp->next = node;
    }

    cout << "success build" << endl;

    return head;
}

int main()
{
    head_buildlist();
    return 0;
}
