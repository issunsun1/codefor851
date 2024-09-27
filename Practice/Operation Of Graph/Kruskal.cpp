#include <iostream>
#include <algorithm>

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

void unionSets(int a, int b)
{
    p[find(a)] = find(b);
}

int main()
{
    cin >> v >> e;
    if (e == 0)
    {
        cout << "impossible" << endl;
        return 0;
    }

    for (int i = 0; i < e; i++)
    {
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }

    // 对图中所有路径按权重从小到大排序
    sort(edge, edge + e);

    // 并查集初始化
    for (int i = 0; i < N; i++)
        p[i] = i; // 初始化

    // res记录最小生成路径 cnt对最小生成树中结点进行计数
    int res = 0, cnt = 0;

    // 遍历所有边
    for (int i = 0; i < e; i++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        if (find(a) != find(b))
        {
            unionSets(a, b);
            res += w;
            cnt++;
        }
    }

    // 如果还有结点未被访问到，则存在无法访问到的独立结点
    if (cnt < v - 1)
        cout << "impossible" << endl;
    else
        cout << res << endl;

    return 0;
}
