class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char, int> mp;
        for(auto it: sentence) mp[it]++;
        
        if(mp.size() < 26) return false;
        return true;
    }
};