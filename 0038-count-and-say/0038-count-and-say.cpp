class Solution {
public:
    
    string mapToString(string s){
        string res = "";
        int x;
        for(int i=0; i<s.length(); i++){
            x = 0;
            char curr = s[i];
            while(i < s.length() && s[i] == curr){
                x++;
                i++;
            }
            i--;
            
            res.push_back(x+'0');
            res.push_back(curr);
        }
        
        return res;
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string toConvert = countAndSay(n-1);
        return mapToString(toConvert);
    }
};