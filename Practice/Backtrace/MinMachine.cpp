/*
3 3 7
1 2 3
3 2 1
2 3 2
1 2 3
5 4 2
2 1 2
*/
#include <iostream>
using namespace std;

const int maxn = 100;
int n, m, cost;    // n个部件，m个供应商，不能超过cost的开销
int w[maxn][maxn]; // w[i][j]表示部件i从供应商j得到的重量
int c[maxn][maxn];
int x[maxn]; // 装每个零件对应的供应商的编号
int res[maxn];
int min_w = 0x3f3f3f3f;

void dfs(int k, int weight, int pay) // 每次搜第k个部件
{
    if (k == 4)
    {
        if (weight < min_w)
        {
            min_w = weight;
            for (int i = 1; i <= m; i++)
            {
                res[i] = x[i];
            }
        }
        return;
    }
    // else
    for (int i = 1; i <= m; i++)
    {
        if (weight + w[k][i] < min_w && pay + c[k][i] <= cost)
        {
            x[k] = i;
            dfs(k + 1, weight + w[k][i], pay + c[k][i]);
            x[k] = 0;
        }
    }
}

int main()
{
    cin >> n >> m >> cost;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= m; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << min_w << endl;
    return 0;
}
