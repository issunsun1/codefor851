#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(int a)
{
    if(a<=1)
        return true;

    for (int i = 2; i < sqrt(a); i++)
    {
        if(a%/2==0)
            return false;
    }

    return true;
}



int main()
{
    
    return 0;
}
