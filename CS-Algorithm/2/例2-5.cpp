#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int check(int n,int m)
{
    if(n<1||m>1)
        return 0;
    if(n==1||m==1)
        return 1;
    if(n<m)
        return check(n, m);
    return check(n, m - 1) + check(n - m, m);
}

int main()
{
    
    return 0;
}
