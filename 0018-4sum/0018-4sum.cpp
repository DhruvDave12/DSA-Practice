class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> stt;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++){
            long long int newTarget1 = target-nums[i];
            
            for(int j=i+1;j<nums.size(); j++){
                long long int newTarget2 = newTarget1-nums[j];
                
                int lo = j+1;
                int hi = nums.size()-1;
                
                while(lo <= hi){
                    vector<int> vec;
                    if(nums[lo]+nums[hi] == newTarget2){
                        if(lo != j && hi != j && lo != hi && lo != i && hi != i && i != j){
                            vec.push_back(nums[i]);
                            vec.push_back(nums[j]);
                            vec.push_back(nums[lo]);
                            vec.push_back(nums[hi]);
                            stt.insert(vec);
                        }
                    }
                    
                    if(nums[lo] + nums[hi] < newTarget2){
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }  
        }
        
        vector<vector<int>> res;
        for(auto it: stt){
            res.push_back(it);
        }
        
        return res;
    }
};