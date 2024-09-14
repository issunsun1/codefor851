#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


// 递归实现x的n次幂函数

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n == -1)
        return 1 / x;
    double left = myPow(x, n / 2);
    double right = myPow(x, n % 2);
    return left * left * right;
}

int main()
{
    
    return 0;
}
