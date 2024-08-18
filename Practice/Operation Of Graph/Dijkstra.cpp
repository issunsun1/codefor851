#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // 定义图和访问数组、距离数组
        vector<vector<long long>> graph(n + 1, vector<long long>(n + 1, INT_MAX));
        vector<long long> distance(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        distance[k] = 0;
        // 初始化图中节点的距离
        for (int i = 1; i <= n; i++)
        {
            graph[i][i] = 0;
        }
        for (auto &time : times)
        {
            graph[time[0]][time[1]] = time[2];
        }

        // n个点，遍历n次
        for (int i = 0; i < n; i++)
        {
            int index = -1, minNum = INT_MAX;
            // 找最近的点
            for (int j = 1; j <= n; j++)
            {
                if (!visited[j] && distance[j] < minNum)
                {
                    index = j;
                    minNum = distance[j];
                }
            }
            // 都遍历过直接退出
            if (index == -1)
            {
                break;
            }
            // 标记当前点访问过
            visited[index] = true;
            // 更新到别的点的最短距离
            for (int v = 1; v <= n; v++)
            {
                if (!visited[v] && graph[index][v] != INT_MAX)
                {
                    if (distance[index] + graph[index][v] < distance[v])
                    {
                        distance[v] = distance[index] + graph[index][v];
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // k到i点没有路径
            if (distance[i] == INT_MAX)
            {
                return -1;
            }
            ans = max(ans, (int)distance[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}
