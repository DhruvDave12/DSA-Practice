class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        
        string s = "";
        int carry = 0;
        
        while(i >= 0 && j >= 0){
            char x = a[i];
            char y = b[j];
            
            int num1 = x-'0';
            int num2 = y-'0';
            
            int sum = num1 + num2 + carry;
            
            if(sum == 1) {
                carry = 0;
                s.push_back('1');
            }
            if(sum == 0) {
                carry = 0;
                s.push_back('0');   
            }
            if(sum == 2) {
                carry = 1;
                s.push_back('0');
            } 
            if(sum == 3){
                carry = 1;
                s.push_back('1');
            }
            i--;
            j--;
        }
        
        while(i >= 0){
            int sum = carry + (a[i]-'0');
            if(sum == 1) {
                carry = 0;
                s.push_back('1');
            }
            if(sum == 0) {
                carry = 0;
                s.push_back('0');   
            }
            if(sum == 2) {
                carry = 1;
                s.push_back('0');
            } 
            if(sum == 3){
                carry = 1;
                s.push_back('1');
            }
            i--;
        }
        while(j >= 0){
            int sum = carry + (b[j]-'0');
            if(sum == 1) {
                carry = 0;
                s.push_back('1');
            }
            if(sum == 0) {
                carry = 0;
                s.push_back('0');   
            }
            if(sum == 2) {
                carry = 1;
                s.push_back('0');
            } 
            if(sum == 3){
                carry = 1;
                s.push_back('1');
            }
            j--;
        }
        
        if(carry == 1){
            s.push_back('1');
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};