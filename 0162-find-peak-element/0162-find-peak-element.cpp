class Solution {
public:
    
    int helper(vector<int>& nums, int start, int end){
        if(end <= start) return -1;
        
        int mid = (end+start)/2;
        
        if(mid == 0 && nums[mid+1] < nums[mid]) return mid;
        else if(mid == 0) return -1;
        
        if(mid == nums.size()-1 && nums[mid-1] < nums[mid]) return mid;
        else if(mid == nums.size()-1) return -1;
        
        if(nums[mid+1]<nums[mid] && nums[mid-1]<nums[mid]) return mid;
        
        int leftSide = helper(nums,start,mid);
        int rightSide = helper(nums,mid+1,end);
        
        if(leftSide != -1) return leftSide;
        if(rightSide != -1) return rightSide;
        
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(nums.size() == 1) return 0;
        
        if(nums[0] > nums[1]) return 0;
        if(nums[end] > nums[end-1]) return end;
        return helper(nums,start,end);
    }
};