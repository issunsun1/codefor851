#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
using namespace std;
const int N = 100000;

typedef int datatype;

typedef struct list
{
    datatype data;
    struct list *next;

} list;

void reverse_list(list *h)
{
    list *p = NULL;
    list *r = h->next;

    while (r != NULL)
    {
        list *temp = r->next;
        r->next = p;
        p = r;
        r = temp;
    }

    h->next = p;
}

int main()
{

    return 0;
}
