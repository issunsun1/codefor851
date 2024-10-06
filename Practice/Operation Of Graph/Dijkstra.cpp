#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

// 单源正权值最短路径
vector<int> dijkstra(vector< vector<int> > &graph, int start)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> visit(n, 0);

    dist[start] = 0;

    for (int i = 0; i < n; ++i)
    {
        int k = -1;

        for (int j = 0; j < n; ++j)
        // 找出距离最近的点
            if (!visit[j] && (k == -1 || dist[k] > dist[j]))
                k = j;

        // 图中所有结点不可达
        if (k == -1)
            break;

        visit[k] = 1; // 加入集合

        for (int j = 0; j < n; ++j)
            if (!visit[j] && graph[k][j] != INF)
                dist[j] = min(dist[j], dist[k] + graph[k][j]);
    }

    return dist;
}