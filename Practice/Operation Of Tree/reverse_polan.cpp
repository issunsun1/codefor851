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

bool isint(char c)
{
    if (c - '0' >= 0 && c - '0' <= 9)
        return true;
    return false;
}

void push(seqstack *s, char a)
{
    s->data[++s->top] = a;
}

char pop(seqstack *s)
{
    return s->data[s->top--];
}

int math(seqstack *s, char *a)
{
    seqstack *p = init();

    for (int i = 0; i <= strlen(a); i++)
    {
        char c = a[i];

        if (isint(c))
            push(p, c);
        else
        {
            int temp1 = pop(s) - '0';
            int temp2 = pop(s) - '0';
            switch (c)
            {
            case '+':
                push(s, temp1 + temp2);

            case '-':
                push(s, temp1 - temp2);

            case '*':
                push(s, temp1 * temp2);

            case '/':
                push(s, temp1 / temp2);
            }
        }
    }

    return pop(s) - '0';
}

int main()
{

    return 0;
}
