#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
const int N = 10000;

int bs(int a[N], int l, int r, int index)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == index)
            return mid;
        if (a[mid] < index)
            l = mid + 1;
        else
            r = mid;
    }

    if (a[l] == index)
        return l;
    else
        return -1;
}

int binary_s(int a[N], int l, int r, int index)
{
    int mid = (l + r) / 2;
    if (a[mid] == index)
        return mid;
    if (a[mid] < index)
        return binary_s(a, mid + 1, r, index);
    else
        return binary_s(a, l, mid - 1, index);
}

int main()
{
    int q, k;
    int a[N];
    scanf("%d%d", &q, &k);
    for (int i = 0; i < q; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < k; j++)
    {
        int temp;
        scanf("%d", &temp);
        cout << bs(a, 0, q - 1, temp) << endl;
    }

    return 0;
}
