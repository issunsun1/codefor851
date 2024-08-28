#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> weight;
vector<int> value;
vector<int> nums;
int bagsize;

// 多重背包问题

int resolution()
{
    
    vector< vector<int> > a(weight.size(), vector<int>(bagsize + 1, 0));

    for (int i = 0; i < bagsize + 1; i++)
        a[0][i] = value[0];

    for (int i = 1; i < weight.size(); i++)
        for (int j = 1; j < bagsize + 1; j++)
        {
            if (j < bagsize)
                a[i][j] = a[i - 1][j];
            else
                for (int k = 1; k <= nums[i] && k * weight[i] <= j; k++)
                    a[i][j] = max(a[i - 1][j], a[i][j - weight[i] * k] + value[i] * k);
        }

    int maxn = 0;
    for (int i = 0; i < weight.size(); i++)
        maxn = max(maxn, a[i][bagsize]);

    return maxn;
}

int main()
{
}