class Solution {
public:
    bool isPalindrome(string s){
        int counter = 0;
        
        for(int i=0; i<s.length()/2; i++){
            if(s[i] == s[s.length()-i-1]) counter++;    
        }
        
        if(counter == s.length()/2) return true;
        return false;
    }
    
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        if(n <= 1) return "";
        // smallest only when we do changes on the starting ones, i.e., even
        
        for(int i=0; i<n; i++){
            if(n%2 != 0 && i == n/2) continue;
            
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                break;
            }
        }
        
        if(isPalindrome(palindrome)){
            palindrome[n-1] = 'b';
        }
        
        return palindrome;
        
    }
};