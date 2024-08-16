#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct circlist
{
    int data;
    circlist *next;
} circlist;

circlist *init_list()
{
    circlist *node = (circlist *)malloc(sizeof(circlist));
    return node;
}

int main()
{
    circlist *L = init_list();
    return 0;
}
