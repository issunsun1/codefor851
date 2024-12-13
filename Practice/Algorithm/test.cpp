#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int sortt(int num)
{
    vector<int> nums;

    while (num > 0)
    {
        nums.push_back(num % 10);
        num /= 10;
    }

    sort(nums.begin(), nums.end());

    int res = 0;
    for (auto n : nums)
        res = res * 10 + n;

    return res;
}

int main()
{
    int n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        int maxn = 0;
        int temp;

        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            int sort_temp = sortt(temp);

            maxn = (maxn > sort_temp) ? maxn : sort_temp;
        }

        cout << maxn << endl;
    }

    return 0;
}
