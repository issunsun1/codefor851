#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 10010;
vector<int> value;
vector<int> weight;
int bagsize;

// 01背包问题(二维数组)

int resolution()
{
    vector< vector<int> > a(weight.size(), vector<int>(bagsize + 1, 0));
    int m = a.size();
    int n = a[0].size();

    vector<int> value;

    for (int i = 1; i < n; i++)
        a[0][i] = value[0];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            if (j < weight[i])
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = max(a[i - 1][j], a[i][j - weight[i]] + value[i]);
        }

    int maxn = 0;
    for (int i = 0; i < m; i++)
        maxn = max(maxn, a[i][n - 1]);

    return maxn;
}

int main()
{
    return 0;
}