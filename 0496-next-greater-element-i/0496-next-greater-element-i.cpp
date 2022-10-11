class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        map<int,int> mp;
        map<int,int> idxVSnge;
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        stack<int> st;
        st.push(nums2[nums2.size()-1]);
        idxVSnge[nums2.size()-1] = -1;
        
        for(int i=nums2.size()-2; i>=0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                idxVSnge[i] = st.top();    
            } else {
                idxVSnge[i] = -1;
            }
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int idx = mp[nums1[i]];
            ans.push_back(idxVSnge[idx]);
        }
        
        return ans;
    }
};