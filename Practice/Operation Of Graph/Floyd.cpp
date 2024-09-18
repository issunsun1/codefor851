#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 时间复杂度 O(V^3)
// 各顶点之间最短路径
// 不允许包含带负权值的边组成的回路

void floydWarshall(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<vector<int>> dist = graph;

    // Floyd算法的核心部分
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // // 打印结果
    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = 0; j < V; j++)
    //     {
    //         if (dist[i][j] == INT_MAX)
    //         {
    //             cout << "INF ";
    //         }
    //         else
    //         {
    //             cout << dist[i][j] << "   ";
    //         }
    //     }
    //     cout << endl;
    // }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}};

    floydWarshall(graph);

    return 0;
}
