class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         int N = nums.size();
         int k = N;
        
        // cycle
        for(int i=0; i<N; i++){
            nums.push_back(nums[i]);
        }
        
        // now apply NGE 1
        
        N = nums.size();
        stack<int> st;
        
        vector<int> res(N,-1);
        
        for(int i=N-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            
            if(!st.empty()){
                res[i] = st.top();
            }
            
            st.push(nums[i]);
        }
        
        return vector(res.begin(),res.begin()+k);
    }
};