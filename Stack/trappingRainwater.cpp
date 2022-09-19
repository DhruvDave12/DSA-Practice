#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;

        for(int i=0; i<height.size(); i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int popped_height = height[st.top()];
                st.pop();
                if(st.empty()) break;
                
                int distance = i-st.top()-1;
                int minHeight = min(height[st.top()], height[i]) - popped_height;

                ans += distance*minHeight;
            }

            st.push(i);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}