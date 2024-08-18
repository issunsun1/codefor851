#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
const int N = 10000;

int v[N];
int dis[N];
int a[N][N];

// 单源正权值最短路径
void dijkstra(int n)
{
    memset(dis, INT_MAX, sizeof(dis)); // 初始化
    v[1] = 1;
    dis[1] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int k = 0;

        for (int j = 1; j <= n; ++j) // 找出距离最近的点
            if (!v[j] && (k == 0 || dis[j] < dis[k]))
                k = j;
        v[k] = 1; // 加入集合

        for (int j = 1; j <= n; ++j) // 松弛
            if (!v[j])
                dis[j] = min(dis[j], dis[k] + a[k][j]);
    }
}

int main()
{

    return 0;
}
