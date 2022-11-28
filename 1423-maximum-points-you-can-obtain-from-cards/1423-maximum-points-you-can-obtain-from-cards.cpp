class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // intuition - 
        // 1. Minimum N-K window sum
        // 2. ans = totalSum - MinimumWindowSum
        
//         int total = 0;
//         for(auto it: cardPoints) total += it;
        
//         int windowSize = cardPoints.size()-k;
        
//         int start = 0;
//         int end = windowSize-1;
        
//         int windowSum = 0;
//         for(int i=0; i<windowSize; i++){
//             windowSum += cardPoints[i];
//         }
        
//         int ans = total-windowSum;
//         int n = cardPoints.size();
        
//         int startLimit = n%2 == 0 ? windowSize-1 : windowSize;
//         int endLimit = n-1;
        
//         while(start < startLimit && end < endLimit){
//             windowSum -= cardPoints[start];
//             start++;
//             end++;
//             windowSum += cardPoints[end];
//             ans = max(ans,total-windowSum);
//         }
//         return ans;
        
        int maxx = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
        }
        maxx = sum;
        for(int i=k-1; i>=0; i--){
            sum -= cardPoints[i];
            sum += cardPoints[cardPoints.size()-k+i];
            
            maxx = max(maxx, sum);
        }
        
        return maxx;
    }
};