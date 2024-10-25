#include <iostream>
#include <algorithm>
using namespace std;
int n;
int x[100][2];
int x1[100];
int x2[100];
int sum1 = 0, sum2 = 0;
int best = 100000;
int num;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void backtrace(int level)
{
    if (level > n)
    {

        sum1 = 0;
        sum2 = 0;
        num = 0;
        for (int i = 1; i <= n; i++)
        {
            sum1 += x[x1[i]][0];
            int temp = max(sum1, sum2);
            sum2 = (temp + x[x1[i]][1]);
            num += sum2;
        }
        if (num < best)
        {
            best = num;
            for (int i = 1; i <= n; i++)
            {
                x2[i] = x1[i];
            }
        }
    }
    else
    {
        for (int i = level; i <= n; i++)
        {
            swap(x1[level], x1[i]);
            backtrace(level + 1);
            swap(x1[level], x1[i]);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            cin >> x[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        x1[i] = i;
    }
    backtrace(1);
    cout << best << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << x2[i] << " ";
    }
    return 0;
}