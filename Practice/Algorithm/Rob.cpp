#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int rob(vector<int> &nums)
{
    int f0 = 0;
    int f1 = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = max(f0 + nums[i], f1);
        f0 = f1;
        f1 = temp;
    }

    return f1;
}