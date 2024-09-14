#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

// 时间复杂度 O(n^2+m) , n表示点数 m表示边数

using namespace std;

const int N = 10000, INF = 0x3f3f3f3f;

int v, e;
int g[N][N]; // 邻接矩阵存储所有边
int dist[N]; // 存储其他点到最小生成树的距离
bool st[N];  // 存储每个点是否已经访问过即是否已经在生成树中

// 如果图不连通,则返回INF,否则返回最小生成树的边权重之和

int prim(vector <vector<int> > &a)
{
    int n = a.size();
    vector<int> dist(n, INF);
    vector<bool> visit(n, false);

    int res = 0;

    for (int i = 0; i < v; i++)
    {

        int t = -1;

        // 寻找未被访问过的节点并且路径最短
        for (int j = 1; j <= n; j++)
            if (!visit[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 当i！= 0 时，判断是否存在不连通的点，如果图不连通则不存在最小生成树
        if (i && dist[t] == INT_MAX)
            return INT_MAX;

        // 将新加入的点存入路径长度寄存器
        if (i)
            res += dist[t];

        // 对已经访问过的点进行标记
        visit[t] = true;

        // 根据新添加进序列的点对未被访问的点进行距离的计算
        for (int j = 1; j <= v; j++)
            dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}
