class Solution {
public:
    bool check(map<int,int> &mp){
        for(auto it: mp){
            if(it.second > 1) return true;
        }
        
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        vector<pair<int,int>> vec;
        
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        
        sort(vec.begin(),vec.end());
        
        for(int i=0; i<vec.size()-1; i++){
            int x = vec[i].first;
            int y = vec[i+1].first;
            if(x == y){
                if(abs(vec[i].second - vec[i+1].second) <= k) return true;
            }
        }
        
        return false;
    }
};