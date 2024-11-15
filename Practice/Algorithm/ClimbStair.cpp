#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int climbStairs(int n)
{
    int N = 10000;
    int a[N];
    if (n <= 1)
        return 1;
    int f0 = 1;
    int f1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = f1 + f0;
        f0 = f1;
        f1 = temp;
    }

    return f1;

    return a[n];
}