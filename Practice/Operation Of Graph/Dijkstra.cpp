#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
const int N = 10000;
const int INF = 0x3f3f3f3f;

// 时间复杂度 O(V^2)

// int v[N];
// int dis[N];
// int a[N][N];

// 单源正权值最短路径
void dijkstra(vector <vector<int> > &graph, int start)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> visit(n, 0);
    // memset(dis, INT_MAX, sizeof(dis)); // 初始化

    dist[start] = 0;

    for (int i = 0; i < n; ++i)
    {
        int k = -1;

        for (int j = 1; j <= n; ++j) // 找出距离最近的点
            if (!visit[j] && (k == -1 || dist[k]>dist[j]))
                k = j;

        // 图中所有结点可达
        if(k==-1)
            break;

        visit[k] = 1; // 加入集合

        for (int j = 1; j <= n; ++j) // 松弛
            if (!visit[j]&&graph[k][j]!=INF)
                dist[j] = min(dist[j], dist[k] + graph[k][j]);
    }
}

int main()
{

    return 0;
}
