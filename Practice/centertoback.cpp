#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef char datatype;

typedef struct seqstack
{
    datatype data[128];
    int top;
} seqstack;

seqstack *init()
{
    seqstack *s = (seqstack *)malloc(sizeof(seqstack));
    s->top = -1;
    return s;
}

datatype top(seqstack *s)
{
    return s->data[s->top];
}

void push(seqstack *s, datatype a)
{
    s->data[++s->top] = a;
}

datatype pop(seqstack *s)
{
    if (s->top == -1)
        return -1;
    return s->data[s->top--];
}

bool empty(seqstack *s)
{
    if (s->top == -1)
        return true;
    else
        return false;
}

int priority(char c)
{
    return (c == '*' || c == '/') ? 2 : 1;
}

bool isint(char c)
{
    return (c - '0' >= 0 && c - '0' <= 9);
}

void ctb(char *a)
{
    seqstack *result = init();
    seqstack *temp = init();
    for (int i = 0; i < strlen(a); i++)
    {
        char c = a[i];
        if (c == '(')
            push(temp, c);
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!empty(temp) && priority(top(temp)) >= priority(c))
                push(result, pop(temp));
            push(result, c);
        }
        else if (c == ')')
        {
            while (!empty(temp) && top(temp) != '(')
                push(result, pop(temp));
            if (!empty(temp) && top(temp) == '(')
                pop(temp);
        }
        else if (isint(c))
        {
            push(result, c);
        }
    }

    while (!empty(temp))
        push(result, pop(temp));
}

int main()
{

    return 0;
}
