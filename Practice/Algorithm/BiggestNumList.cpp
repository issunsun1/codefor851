#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 最大子数组和

int calculate(vector<int> nums)
{
    int maxn = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = max(sum,0)+nums[i];
        maxn = max(maxn, sum);
    }
    return maxn;
}

int main()
{

    return 0;
}
