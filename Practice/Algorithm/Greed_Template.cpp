#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


// 贪心模版
struct activity
{
    int id;  // 编号
    int s;   // 开始时间
    int f;   // 结束时间
    int v;   // 价值
    int w;   // 重量
    int vis; // 标记是否需要选中
};
bool cmp(activity a, activity b)
{
    return a.f < b.f;
}
void solve(activity arr[], int n)
{
    int endtime = 0;
    int c, valRes;
    sort(arr + 1, arr + n, cmp); // 表示排序下标从arr[1]-arr[n-1]的元素排序
    for (int i = 1; i <= n; i++)
    {
        // 1、装载
        if (false)
        { // 容量已超，已装满
            // 或者装部分
            break;
        }
        else
        {
            valRes += arr[i].v;
            c -= arr[i].w;
            arr[i].vis = 1;
        }
        // 2、活动安排
        if (arr[i].s >= endtime)
        {
            arr[i].vis = 1;
            endtime = arr[i].f;
        }
    }
}