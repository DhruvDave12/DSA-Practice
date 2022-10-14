class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int i = 1;
        
        for(auto it: target){
            while(i != it){
                res.push_back("Push");
                res.push_back("Pop");
                i++;
            }
            res.push_back("Push");
            i++;
        }
        
        return res;
    }
};