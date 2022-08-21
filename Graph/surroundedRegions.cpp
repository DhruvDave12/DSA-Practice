#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    bool isEdge(int i, int j, int n, int m){
        if(i == 0 || i == n-1) return true;
        if(j == 0 || j == m-1) return true;
        return false;
    }

    void dfs(vector<vector<char>> &board, int i, int j, char newVal)
    {
        int n = board.size();
        int m = board[0].size();

        if(i < 0 || j < 0) return;
        if(i >= n || j >= m) return;
        if(board[i][j] != 'O') return;

        if(board[i][j] == 'O'){
            board[i][j] = newVal;
        }

        dfs(board, i-1, j, newVal);
        dfs(board, i+1, j, newVal);
        dfs(board, i, j-1, newVal);
        dfs(board, i, j+1, newVal);
    }

    void solve(vector<vector<char>> &board)
    {
        char newVal = '$';
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(isEdge(i,j,board.size(), board[0].size())){
                    dfs(board, i, j, newVal);
                }
            }
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == newVal){
                    board[i][j] = 'O';
                }
            }
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                cout<<board[i][j]<<" ";
            }cout<<"\n";
        }

    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<vector<char>> vec = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    Solution s;
    s.solve(vec);
    return 0;
}