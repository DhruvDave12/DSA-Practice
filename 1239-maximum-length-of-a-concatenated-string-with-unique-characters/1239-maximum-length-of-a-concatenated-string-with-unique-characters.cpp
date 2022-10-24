class Solution {
public:
    bool hasAllUnique(string s){
        sort(s.begin(), s.end());
        
        for(int i=0; i<(int)s.length()-1; i++){
            if(s[i] == s[i+1]) return false;
        }
        
        return true;
    }
    
    void getAllCombos(vector<string> & arr, int i, string firstStr, int &maxAns){
        if(!hasAllUnique(firstStr)) return;
        
        if(i == arr.size()){
            int size = firstStr.length();
            maxAns = max(maxAns, size);
            return;
        }
        
        getAllCombos(arr, i+1, firstStr, maxAns);
        getAllCombos(arr, i+1, firstStr+arr[i], maxAns);
    }
    
    int maxLength(vector<string>& arr) {
        int ans = 0;
        getAllCombos(arr,0,"",ans);
        
        return ans;
    }
};