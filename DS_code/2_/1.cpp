#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 100000;

typedef int datatype;

typedef struct linklist
{
    datatype data;
    struct linklist *next;
} linklist;

void delete_x(linklist *h, datatype index)
{
    linklist *pre = h, *rear = h->next;
    while (rear != NULL)
    {
        if (rear->data == index)
        {
            linklist *temp = rear;
            pre->next = rear;
            rear = rear->next;
            free(temp);
        }
        else
        {
            pre = pre->next;
            rear = rear->next;
        }
    }
}

int main()
{

    return 0;
}
