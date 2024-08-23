#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 邻接表表示图
vector<vector<int>> adj = {{}, {0}, {0}, {1, 2}, {3}, {3}};

// 保存每个节点的入度
vector<int> indegree = {0, 1, 1, 2, 1, 1};

// 拓扑排序函数
void topological_sort()
{
    // 创建一个队列存储入度为0的节点
    queue<int> q;
    // 遍历所有节点，将入度为0的节点加入队列
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    // 记录输出节点数
    int count = 0;
    // 当队列不为空时循环
    while (!q.empty())
    {
        // 取出队首节点并输出
        int u = q.front();
        q.pop();
        cout << u << " ";
        count++;
        // 遍历该节点指向的所有节点
        for (int v : adj[u])
        {
            // 将其入度减一
            indegree[v]--;
            // 如果其入度变为0，则加入队列
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    cout << endl;
    // 如果输出节点数不等于总节点数，则说明图中存在环路
    if (count != indegree.size())
    {
        cout << "The graph has a cycle." << endl;
    }
}

int main()
{
    topological_sort();
}