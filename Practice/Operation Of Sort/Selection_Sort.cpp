#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 1000;

void select_sort(int a[N], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[min], a[i]);
    }
}

int main()
{

    return 0;
}
