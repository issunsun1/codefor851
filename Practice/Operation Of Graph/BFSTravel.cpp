#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector< vector<int> > graph;
vector< pair<int, int> > move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int orangesRotting(vector< vector<int> > &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue< pair<int, int> > q;
    int freshOranges = 0;

    // 初始化队列，统计新鲜橘子的数量
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                freshOranges++;
            }
        }

    int min_step = 0;

    // BFS遍历
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto temp = q.front();
            q.pop();
            int ni = temp.first;
            int nj = temp.second;

            for (auto p : move)
            {
                int new_i = ni + p.first;
                int new_j = nj + p.second;
                if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < m && grid[new_i][new_j] == 1)
                {
                    grid[new_i][new_j] = 2; // 腐烂
                    q.push({new_i, new_j});
                    freshOranges--; // 统计已腐烂的新鲜橘子
                }
            }
        }
        if (!q.empty())
            min_step++; // 只有在队列非空时才增加步数
    }

    return freshOranges == 0 ? min_step : -1; // 检查是否还有新鲜橘子
}
