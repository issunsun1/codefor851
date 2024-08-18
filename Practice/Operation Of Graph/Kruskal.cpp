#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 10000;

int v, e;
int p[N]; // 并查集的父节点数组

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edge[N];

// 并查集基本操作
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &v, &e);
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i].a = a;
        edge[i].b = b;
        edge[i].w = w;
    };

    // 对图中所有路径按权重从小到大排序
    sort(edge, edge + e);

    // 并查集初始化
    for (int i = 1; i <= v; i++)
        p[i] = i;

    // res记录最小生成路径 cnt对最小生成树中结点进行计数，并且在最后进行判断是否完全访问图中的所有结点
    int res = 0, cnt = 0;

    // 遍历所有边，边数据结构已经是有序的，因此只需要不断遍历选取添加
    for (int i = 0; i < e; i++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    // 如果还有结点未被访问到，则表明存在无法访问到的独立结点，因此不存在最小生成树
    if (cnt < v - 1)
        cout << "impossible" << endl;

    // 如果所有结点都被访问到，则表明存在最小生成树并返回最小路径
    else
        cout << res;

    return 0;
}
