class Solution {
public:

    void sortStrs(vector<string> &strs){
        for(int i=0; i<strs.size(); i++){
            for(int j=i+1; j<strs.size(); j++){
                if(strs[j].length() > strs[i].length()){
                    swap(strs[i],strs[j]);
                }
            }
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        sortStrs(strs);
        vector<pair<char,int>> vec(strs[0].size());
        for(int j=0; j<strs[0].length(); j++){
            vec[j] = make_pair(strs[0][j], 1);
        }
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<strs[i].length(); j++){
                if(vec[j].first == strs[i][j]){
                    vec[j].second++;
                }
            }
        }

        string ans = "";
        for(auto it: vec){
            if(it.second == strs.size()){
                ans.push_back(it.first);
            } else {
                break;
            }
        }
        
        return ans;

    }
};