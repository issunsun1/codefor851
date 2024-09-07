#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int v, n;
    cin >> v >> n;
    vector<int> value(n);
    for (int i = 0; i < n; i++)
        cin >> value[i];

    vector<vector<int>> a(n + 1, vector<int>(v + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (j >= value[i - 1])
                a[i][j] = max(a[i - 1][j], a[i - 1][j - value[i - 1]] + value[i - 1]);
            else
                a[i][j] = a[i - 1][j];
        }
    }

    cout << v - a[n][v] << endl;

    return 0;
}
