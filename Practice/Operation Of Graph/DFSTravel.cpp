#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector< pair<int, int> > movement = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector< vector<int> > visit;
int n, m;

void dfs(vector< vector<int> > &grid, vector< vector<int> > &visit, int i, int j, int &count)
{
    if (visit[i][j] || grid[i][j] == 0) // 如果已访问或不是岛屿，返回
        return;

    visit[i][j] = 1; // 标记为已访问
    count++;         // 增加岛屿面积计数

    for (auto p : movement)
    {
        int new_x = i + p.first;
        int new_y = j + p.second;
        if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m)
        {
            dfs(grid, visit, new_x, new_y, count);
        }
    }
}

int maxAreaOfIsland(vector< vector<int> > &grid)
{
    n = grid.size();
    m = grid[0].size();
    int maxarea = 0; // 初始化为 0
    visit = vector< vector<int> >(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !visit[i][j])
            { // 只有未访问的岛屿部分才进行 DFS
                int count = 0;
                dfs(grid, visit, i, j, count);
                maxarea = max(maxarea, count); // 更新最大面积
            }
        }
    }

    return maxarea;
}
