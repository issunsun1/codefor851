#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


    int maxSubArray(vector<int>& nums) {
        int f = 0,sum = INT_MIN;
        for(int i = 0;i < nums.size();i++)
        {
            f = max(f,0)+nums[i];
            sum = max(sum,f);
        }

        return sum;
    }