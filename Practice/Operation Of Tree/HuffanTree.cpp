#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 10000;

typedef struct huffmannode
{
    int val;
    huffmannode *lchild;
    huffmannode *rchild;
} huffmannode, *huffmanTree;

huffmannode *createnode(int val)
{
    huffmannode *p = (huffmannode *)malloc(sizeof(huffmannode));
    p->lchild = nullptr;
    p->rchild = nullptr;
    p->val = val;

    return p;
}

huffmanTree init(vector<huffmannode *> a)
{
    sort(a.begin(), a.end(), [](huffmannode *h1, huffmannode *h2)
         { return h1->val < h2->val; });
    reverse(a.begin(), a.end());

    int min1 = a.back();
    a.pop_back();
    int min2 = a.back();
    a.pop_back();

    while (!a.empty())
    {
    }
}

int main()
{

    return 0;
}
