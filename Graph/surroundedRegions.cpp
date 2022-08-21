#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &vis)
    {
        if (i < 0 || i >= board.size())
            return;
        if (j < 0 || j >= board[0].size())
            return;

        if (board[i][j] == 'O')
            board[i][j] = '~';

        vis[i][j] = true;

        if(!vis[i+1][j]){
            dfs(board, i + 1, j, vis);
        }                
        if(!vis[i-1][j]){
            dfs(board, i - 1, j, vis);
        }
        if(!vis[i][j+1]){
            dfs(board, i, j + 1, vis);
        }
        if(!vis[i][j-1]){
            dfs(board, i, j - 1, vis);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i, vis);
            if (board[board[0].size() - 1][i] == 'O')
                dfs(board, board[0].size() - 1, i, vis);
            if (board[i][0] == 'O')
                dfs(board, i, 0, vis);
            if (board[i][board[0].size() - 1] == 'O')
                dfs(board, i, board[0].size() - 1, vis);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> vec = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    Solution s;
    s.solve(vec);
    return 0;
}