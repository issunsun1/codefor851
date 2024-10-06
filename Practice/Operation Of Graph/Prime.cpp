#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 0x3f3f3f3f;

// 如果图不连通, 则返回INF, 否则返回最小生成树的边权重之和
int prim(vector< vector<int> > &graph)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visit(n, false);
    int res = 0;

    dist[0] = 0; // 从第一个节点开始
    
    for (int i = 0; i < n; i++)
    {
        int t = -1;

        // 寻找未被访问过的节点并且路径最短
        for (int j = 0; j < n; j++)
            if (!visit[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 当i != 0 时，判断是否存在不连通的点，如果图不连通则不存在最小生成树
        if (dist[t] == INF)
            return INF;

        // 将新加入的点存入路径长度寄存器
        res += dist[t];
        visit[t] = true;

        // 根据新添加进序列的点对未被访问的点进行距离的计算
        for (int j = 0; j < n; j++)
            if (!visit[j])
                dist[j] = min(dist[j], dist[t]+graph[t][j]);
    }

    return res;
}

