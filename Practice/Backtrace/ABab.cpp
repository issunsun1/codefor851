// 字母大小写全排列
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> ans;

void dfs(string &s, int i)
{
    if (i == s.size())
    {
        ans.emplace_back(s);
        return;
    }
    if (isdigit(s[i]))
    {
        dfs(s, i + 1);
    }
    else
    {
        s[i] = tolower(s[i]);
        dfs(s, i + 1);

        s[i] = toupper(s[i]);
        dfs(s, i + 1);
    }
}
vector<string> letterCasePermutation(string s)
{
    dfs(s, 0);
    return ans;
}
