class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        
        // monotonous stack
        stack<int> st;
        
        for(int i=0; i<height.size(); i++){
            while(!st.empty() && height[st.top()] < height[i]){
                st.pop();
            }
            if(!st.empty()){
                leftMax[i] = height[st.top()]; 
            }
            if(!st.empty()){
                if(height[st.top()] < height[i]){
                    st.push(i);
                }
            } else {
                st.push(i);
            }
            
        }
        
        st = stack<int>();
        
        for(int i=height.size()-1; i>=0; i--){
            while(!st.empty() && height[st.top()] < height[i]){
                st.pop();
            }
            if(!st.empty()){
                rightMax[i] = height[st.top()];
            }
            if(!st.empty()){
                if(height[st.top()] < height[i]){
                    st.push(i);
                }
            } else {
                st.push(i);
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<height.size(); i++){
            if(height[i] < min(leftMax[i],rightMax[i])){
                ans += min(leftMax[i],rightMax[i])-height[i];
            }
            
        }
        
        return ans;
        
    }
};