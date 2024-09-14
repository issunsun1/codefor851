#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int check(vector< vector<int> > a,int i,int j)
{
    int mi = 0, mj = 0, m = 0;
    if(i-1>0&&a[i][j]-a[i-1][j]>m)
        m = a[i][j] - a[i - 1][j];
    if(i+1<a.size()&&a[i][j]-a[i+1][j]>m)
        m = a[i][j] - a[i + 1][j];
    if(j-1>0&&a[i][j]-a[i][j-1]>m)
        m = a[i][j] - a[i][j-1];
    if(j+1<a[0].size()&&a[i][j]-a[i][j+1])
        m = a[i][j] - a[i][j + 1];

    return m == 0 ? -1 : m;
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector< vector<int> > a(r, vector<int>(c, 0));

    for (int i = 0; i < r;i++)
        for (int j = 0; j < c;j++)
        {
            cin >> a[i][j];
        }
    int mi = 0, mj = 0, m = 0;

    for (int i = 0; i < r;i++)
        for (int j = 0; j < c;j++)
        {
            if(a[i][j]>m)
            {    
                m = a[i][j];
                mi = i;
                mj = j;
            }
        }

    int count = 0;

    



    return 0;
}
