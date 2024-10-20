#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


// 分支限界框架
struct fNode
{
    int step;
    int data;
};
void bfs()
{
    queue<fNode> q;
    // 根结点初始化
    fNode now, next; // now指当前节点，next表示下一层节点
    now.step = 0;
    // 入队并标记
    q.push(now);
    while (!q.empty())
    {
        // 出队，取队首元素
        now = q.front();
        q.pop();
        // 计算
        next.step = now.step + 1;
        next.data = now.data; // 具体计算逻辑视题目定
        // 做选择
        if (true)
        {
            // 孩子入队并标记
            q.push(next);
            // 更新最优解
        }
        // 做另一个选择
        if (true)
        { // 剪枝条件，不满足的可直接退出
            now.step++;
            q.push(now);
        }
    }
}