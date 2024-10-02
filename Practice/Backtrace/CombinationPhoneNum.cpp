#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// 定义普通函数dfs，用于深度优先搜索
void dfs(int i, int n, string digits, string &path, vector<string> &ans)
{
    if (i == n)
    {
        ans.emplace_back(path);
        return;
    }
    for (char c : MAPPING[digits[i] - '0'])
    {
        path[i] = c;
        dfs(i + 1, n, digits, path, ans);
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    int n = digits.length();
    if (n == 0)
        return ans;
    
    string path(n, 0);
    // 调用dfs函数，开始深度优先搜索
    
    dfs(0, n, digits, path, ans);
    return ans;
}