#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    void helper(int i, int j, vector<int> &TargetPos, int N, vector<int> &vec, int steps){
        if(i >= N || j >= N || i < 0 || j < 0) return;
        if(i == TargetPos[0] and j == TargetPos[1]){
            vec.push_back(steps);
            return;
        }

        helper(i-1,j-2,TargetPos,N,vec,steps+1);
        helper(i-1,j+2,TargetPos,N,vec,steps+1);
        helper(i+1,j-2,TargetPos,N,vec,steps+1);
        helper(i+1,j+2,TargetPos,N,vec,steps+1);

        return;
    }

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<int> vec;
        
        helper(KnightPos[0], KnightPos[1],TargetPos,N,vec,0);
        int ans = INT_MAX;
        for(int i=0; i<vec.size(); i++){
            ans = min(ans,vec[i]);
            cout<<vec[i]<<" ";
        }
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> knight = {4,5};
    vector<int> target = {1,1};

    int N = 6;
    Solution s;
    int x = s.minStepToReachTarget(knight, target, N);

    cout<<"FINAL ANS: "<<x<<"\n";
    return 0;
}