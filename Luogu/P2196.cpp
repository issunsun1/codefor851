#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(vector< vector<int> > ans,int n)
{
    for (int i = 1; i < ans.size();i++)
        if(ans[n][i]==1)
            return true;
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> order(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int maxi = 0;
    int maxn = nums[0];
    for (int i = 1; i < n;i++)
        if(nums[i]>maxn)
        {
            maxn = nums[i];
            maxi = i;
        }

    vector< vector<int> > adjoin(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            cin >> adjoin[i][j];
        }
    }

    order.push_back(maxi);

    int sum = maxn;

    while(check(adjoin,maxi))
    {
        int temp_max = nums[maxi+1];
        int i = maxi + 2;
        for (i; i < adjoin.size(); i++)
        {
            if(adjoin[maxi][i]==1)
            {
                if(temp_max<nums[i])
                {
                    temp_max = nums[i];
                    maxi = i;
                }
            }
        }
        order.push_back(maxi);
        sum += temp_max;
    }

    for (int i = 0; i < order.size();i++)
        cout << order[i] <<" ";
    cout << sum;

    return 0;
}
