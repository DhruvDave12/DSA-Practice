#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        double res = 0;
        for(int i=0; i<k; i++){
            sum += k;
        }

        res = (double) sum / k;

        for(int i=k; i<nums.size(); i++){
            sum += nums[i];
            sum -= nums[i-k];
            double avg = (double) sum / k;
            if(avg > res){
                res = avg;
            }
        }

        return res*1.0000;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}