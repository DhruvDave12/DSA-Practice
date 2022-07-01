#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int gamesWon = 0;
    int gameWon (vector<string> & boards){
        // row check
        int counter = 0;
        for(int i=0; i<boards.size(); i++){
            counter == 0;
            for(int j=0; j<boards[i].size()-1; j++){
                if(boards[i][j] == boards[i][j+1] && (boards[i][j] == 'O' || boards[i][j] == 'X')) counter++;
            }
            if (counter==2) gamesWon++;
        }

        // diagonal check
        if(boards[0][0] == boards[1][1] && boards[1][1] == boards[2][2] && (boards[0][0] == 'X' || boards[0][0] == 'O')){
            gamesWon++;
        }
        if(boards[0][2] == boards[1][1] && boards[1][1] == boards[2][0] && (boards[0][2] == 'X' || boards[0][2] == 'O')){
            gamesWon++;
        }

        // column check 
        if(boards[0][0] == boards[1][0] && boards[1][0] == boards[2][0] && (boards[0][0] == 'X' || boards[0][0] == 'O')){
            gamesWon++;
        }
        if(boards[0][1] == boards[1][1] && boards[1][1] == boards[2][1] && (boards[0][1] == 'X' || boards[0][1] == 'O')){
            gamesWon++;
        }
        if(boards[0][2] == boards[1][2] && boards[1][2] == boards[2][2] && (boards[0][2] == 'X' || boards[0][2] == 'O')){
            gamesWon++;
        }

        return gamesWon;
    }

    bool validTicTacToe(vector<string>& board) {
        int totalWins = gameWon(board);
        int X = 0;
        int O = 0;
        // count X and O
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == 'X'){
                    X++;
                }
                else if(board[i][j] == 'O'){
                    O++;
                }
            }
        }

        if(X-O == 1 || X-O == 0 && gamesWon <= 1){
            return true;
        }
        return false;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}