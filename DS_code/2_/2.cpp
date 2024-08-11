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

int search_min(list *h)
{
    datatype min = h->next->data;
    list *temp = h->next;
    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;

        temp = temp->next;
    }
    return min;
}

int main()
{

    return 0;
}
