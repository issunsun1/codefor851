#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector< vector<string> > ans;

bool check(vector< vector<string> > &board, int row, int col)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
        if (board[i][col] == "Q")
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == "Q")
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == "Q")
            return false;
    return true;
}

void dfs(vector<string> &board,int x)
{
    if(x==board.size())
    {
        ans.push_back(board);
        return;
    }
    int n = board.size();

    for (int i = 0; i < n;i++)
    {
        if(check(board,x,i))
            continue;
        board[x][i] = 'Q';
        dfs(board, x + 1);
        board[x][i] = '.';
    }
}



vector< vector<string> > solve(int n)
{
    vector<string> board(n, string(n, '.'));
    dfs(board, 0);
    return ans;
}
