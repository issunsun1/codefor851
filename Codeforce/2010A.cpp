#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


int main()
{
    int t, n;
    vector<int> ans;
    cin >> t;
    for (int i = 0; i < t;i++)
    {
        cin >> n;
        vector<int> temp;
        int flag = 1;
        for (int j = 0; j < n; j++)
            cin >> temp[j];

        int sum = 0;

        for (int k = 0; k < temp.size(); k++)
        {
            sum += flag * temp[k];
            flag *= -1;
        }

        ans.push_back(sum);
    }

    for (int i = 0; i < ans.size();i++)
        cout << ans[i] << endl;

    return 0;
}
