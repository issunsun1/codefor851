#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 拓扑排序应用

vector<int> findtopsort(vector< vector<int> > & course,int coursenum)
{
    vector< vector<int> > neighbor(course.size(),vector<int>(course.size(),0));
    vector<int> ans;
    vector<int> incount(coursenum, 0);
    queue<int> q;

    int n = course.size();
    int m = course.size();

    
    // 构建邻接矩阵和入度数组
    for (int i = 0;i < n;i++)
    {

        neighbor[course[i][1]].push_back(course[i][0]);
        incount[course[i][0]]++;
    }

    for (int i = 0; i < n;i++)
        if(incount[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for (int i = 0; i < neighbor[temp].size();i++)
        {
            incount[neighbor[temp][i]]--;
            if(incount[neighbor[temp][i]]==0)
                q.push(i);
        }
    }

    if(ans.size()!=coursenum)
        return ans;  //返回空向量
    return ans;
}