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

void delete_s(list *h, int a, int b)
{
    list *p = h;
    list *r = h->next;
    while (r != NULL)
    {
        // link *temp = r;
        if (r->data > a && r->data < b)
        {
            temp
        }
    }
}

int main()
{

    return 0;
}
