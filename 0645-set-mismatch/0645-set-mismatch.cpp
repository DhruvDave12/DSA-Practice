class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int> stats(N+1, false);
        
        map<int,int> mp;
        for(auto it: nums) {
            mp[it]++;
            stats[it] = true;
        };
        
        vector<int> res;
        for(auto it: mp){
            if(it.second > 1){
                res.push_back(it.first);
                break;
            }
        }
        
        for(int i=1; i<=N; i++){
            if(stats[i] == false){
                res.push_back(i);
                break;
            }
        }
        
        
        return res;
    }
};