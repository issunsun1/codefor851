#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef int datatype;

const int N = 100000;

typedef struct
{
    datatype data[N];
    int top;
} seqstack;

seqstack *init()
{
    seqstack *s;
    s = (seqstack *)malloc(sizeof(seqstack));
    s->top = -1;
    return s;
}

void push(datatype a, seqstack *s)
{
    s->data[++s->top] = a;
}

datatype pop(seqstack *s)
{
    // 判断顺序栈是否为空
    if (s->top == -1)
        return -1;

    return s->data[s->top--];
}

int main()
{

    return 0;
}
