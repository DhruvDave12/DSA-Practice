class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";
        
        for(const string& it: word1){
            s1.append(it);
        }
        
        for(const string& it: word2){
            s2.append(it);
        }
        
        if(s1 == s2) return true;
        return false;
    }
};