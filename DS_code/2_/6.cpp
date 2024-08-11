#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 100000;

typedef int datatype;

typedef struct list
{
    datatype data;
    struct list *next;

} list;

list split(list *h)
{
    list *p = h->next;
    list *r;
    if (p->next != NULL && p->next->next != NULL)
        r = p->next->next;
    while (r != NULL)
    {
        p = p->next;
        r = r->next;
    }
}

int main()
{

    return 0;
}
