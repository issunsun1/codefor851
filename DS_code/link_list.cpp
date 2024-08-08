#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef int datatype;

typedef struct list{
    datatype element;
    struct list *next;
} list;

list *init()
{
    list *link;
    link = (list *)malloc(sizeof(link));
    return link;
}

void add(datatype element, list *link)
{
    list *temp = link;
    while(temp->next != NULL)
        temp = temp->next;
    list * new_point = (list *)malloc(sizeof(list));
    new_point -> element = element;
    temp->next = new_point;
}

int
main()
{
    
    return 0;
}
