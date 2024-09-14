#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int r;
    cin >> r;

    vector< vector<int> > a(r, vector<int>(r, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                a[i][j] += a[i - 1][j];
            }
            else if (j == i)
            {
                a[i][j] += a[i - 1][j - 1];
            }
            else
            {
                a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
            }
        }
    }

    int maxn = 0;
    for (int i = 0; i < r; i++)
    {
        maxn = max(a[r - 1][i], maxn);
    }
    cout << maxn << endl;

    return 0;
}
