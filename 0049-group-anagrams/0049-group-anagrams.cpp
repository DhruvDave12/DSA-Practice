class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> temp;
        
        for(int i=0; i<strs.size(); i++){
            string t = strs[i];
            sort(t.begin(),t.end());
            temp.push_back({t,i});
        }
        sort(temp.begin(), temp.end());
        
        map<string, vector<string>> mp;
        for(auto it: temp){
            // cout<<it.first<<" "<<it.second<<"\n";
            mp[it.first].push_back(strs[it.second]);
        }
        vector<vector<string>> ans;
        
        for(auto it: mp){
            vector<string> s;
            for(auto itr: it.second){
                s.push_back(itr);
            }
            
            ans.push_back(s);
        }
        return ans;
    }
};