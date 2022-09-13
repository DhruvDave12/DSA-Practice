#include <bits/stdc++.h>
using namespace std;

class cellDS {
    public:
    int x;
    int y;
    int dis;

    cellDS(int x, int y, int dis){
        this->dis = dis;
        this->x = x;
        this->y = y;
    }
};

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.

    // can be solved using DFS also but here it is better to use BFS
    bool isIn(int i, int j, int row, int col){
        if(i < 0 || j < 0) return false;
        if(i >= row || j >= col) return false;
        return true;
    }

    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
        int row = N;
        int col = N;

        vector<vector<bool>> vis(N+1, vector<bool>(N+1, false));
        queue<cellDS> q;
        vis[KnightPos[0]][KnightPos[1]] = true;
        q.push(cellDS(KnightPos[0], KnightPos[1], 0));

        vector<int> dX = {-2,-1,1,2,-2,-1,1,2};
        vector<int> dY = {-1,-2,-2,-1,1,2,2,1};
        int x, y;
        while(!q.empty()){
            cellDS temp = q.front();
            if(temp.x == TargetPos[0] && temp.y == TargetPos[1]) {
                return temp.dis;
            }

            // else we traverse in DFS
            for(int i=0; i<8; i++){
                x = temp.x + dX[i];
                y = temp.y + dY[i];

                if(isIn(x,y,row,col) && !vis[x][y]){
                    vis[x][y] = true;
                    q.push(cellDS(x,y,temp.dis+1));
                }
            }    
            
        }

        return -1;
	}
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}