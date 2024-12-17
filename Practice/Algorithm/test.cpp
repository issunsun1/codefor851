#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int bagsize;
vector<int> value;
vector<int> nums;
vector<int> weight;

int mutibag()
{
    vector< vector<int> > dp(nums.size() + 1,vector<int>(bagsize + 1));
    for (int i = 0; i < bagsize + 1;i++)
        dp[0][i] = 0;
    for (int i = 1; i < nums.size() + 1;i++)
        for (int j = 0; j < bagsize + 1;j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k < nums[i - 1]&&k*weight[i-1]<=j;k++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - k * weight[i - 1]] + value[i - 1] * k);
        }

    return dp[nums.size()][bagsize];
}

int a01bag()
{
    vector< vector<int> > dp(nums.size() + 1, vector<int>(bagsize + 1,0));
    for (int i = 1; i < nums.size()+1;i++)
    {
        for (int j = 1; j < bagsize + 1;j++)
        {
            if(weight[i-1]<j)
                dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weight[i - 1]] + value[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[nums.size()][bagsize];
}

int coinchange()
{
    int minn = 0x3f3f3f3f;
    vector< vector<int> > dp(nums.size() + 1,vector<int>(bagsize+1,minn ));
    dp[0][0] = 0;
    for (int i = 1; i < nums.size() + 1; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j < bagsize + 1; j++)
        {
            if(weight[i-1]<j)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[nums.size()][bagsize] == minn ? -1 : dp[nums.size()][bagsize];
}

vector<vector<int> > res;
void dfs(vector<int> &path,int x)
{
    if(x==path.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = x; i < path.size();i++)
    {
        swap(path[x], path[i]);
        dfs(path, x + 1);
        swap(path[x], path[i]);
    }
}

int floyd(vector<vector<int> > graph)
{
    int n = graph.size();
    vector< vector<int> > dist = graph;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n;i++)
            for (int j = 0; j < n;j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
}

void down(vector<int> a,int start,int end)
{
    int parent = start;
    int child = parent * 2 + 1;
    while(child<=end)
    {
        if(child+1<=end&&a[child]>a[child+1])
            child++;
        if(a[parent]<a[child])
            return;
        else
        {
            swap(a[child], a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

