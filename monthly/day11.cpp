#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    deque<int> dq;
    int minOperations(vector<int> &nums, int x)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            dq.push_back(nums[i]);
        }
        int counter = 0;

        while (!dq.empty())
        {
            int A = dq.front();
            int B = dq.back();
            // cout<<dq.size()<<"\n";
            if (x == 0)
            {
                return counter;
            }
            // cout<<"COUNTER: "<<counter<<"\n";
            // cout<<"x: "<<x<<"\n";
            if (A > x && B > x)
            {
                counter += 2;
                if (dq.back())
                {
                    dq.pop_back();
                }
                if (dq.front())
                {
                    dq.pop_front();
                }
                continue;
            }
            else
            {
                int y;
                if (((x - A) >= 0) && ((x - A) < (x - B)))
                {
                    y = A;
                }
                else if (((x - B) < (x - A)) && ((x - B) >= 0))
                {
                    y = B;
                }

                // cout<<dq.size()<<"\n";
                // cout<<"Y: "<<y<<"\n";
                if (y == A)
                {
                    // if(y > x){
                    //     y = B;
                    // }
                    // cout<<"Y"<<y<<"\n";

                    x = x - y;
                    // if(y == A){
                    //     dq.pop_front();
                    // }
                    // else{
                    //     dq.pop_back();
                    // }
                    dq.pop_front();
                    counter++;
                    continue;
                }
                else if (y == B)
                {
                    // if(y > x){
                    //     y = A;
                    // }
                    // cout<<"Y"<<y<<"\n";
                    x = x - y;
                    // if(y == A){
                    //     dq.pop_front();
                    // }
                    // else{
                    //     dq.pop_back();
                    // }
                    dq.pop_back();
                    counter++;
                    continue;
                }
                else
                {
                    if (dq.front())
                    {
                        dq.pop_front();
                    }
                    if (dq.back())
                    {
                        dq.pop_back();
                    }
                    counter += 2;
                }
            }
        }
        if (x == 0)
        {
            return counter;
        }
        return -1;
    }
};

class Solution1
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0, n = nums.size();
        for (int i : nums)
            sum += i;
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int start_idx = 0;
        bool found = false;
        for (int end_idx = 0; end_idx < n; end_idx++)
        {
            curr_sum += nums[end_idx];
            while (start_idx <= end_idx && curr_sum > target)
            {
                curr_sum -= nums[start_idx];
                start_idx += 1;
            }
            if (curr_sum == target)
            {
                found = true;
                max_len = max(max_len, end_idx - start_idx + 1);
            }
        }
        return found ? n - max_len : -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {5207, 5594, 477, 6938, 8010, 7606, 2356, 6349, 3970, 751, 5997, 6114, 9903, 3859, 6900, 7722, 2378, 1996, 8902, 228, 4461, 90, 7321, 7893, 4879, 9987, 1146, 8177, 1073, 7254, 5088, 402, 4266, 6443, 3084, 1403, 5357, 2565, 3470, 3639, 9468, 8932, 3119, 5839, 8008, 2712, 2735, 825, 4236, 3703, 2711, 530, 9630, 1521, 2174, 5027, 4833, 3483, 445, 8300, 3194, 8784, 279, 3097, 1491, 9864, 4992, 6164, 2043, 5364, 9192, 9649, 9944, 7230, 7224, 585, 3722, 5628, 4833, 8379, 3967, 5649, 2554, 5828, 4331, 3547, 7847, 5433, 3394, 4968, 9983, 3540, 9224, 6216, 9665, 8070, 31, 3555, 4198, 2626, 9553, 9724, 4503, 1951, 9980, 3975, 6025, 8928, 2952, 911, 3674, 6620, 3745, 6548, 4985, 5206, 5777, 1908, 6029, 2322, 2626, 2188, 5639};
    // vector<int> nums = {1,2,3,4,5};

    // cout<<"NUMS: "<<nums.size()<<"\n";
    int x = 565610;
    // int x = 20;
    Solution s;
    int ans = s.minOperations(nums, x);

    cout << "ANS: " << ans << "\n";
    return 0;
}

/*
[5207,5594,477,6938,8010,7606,2356,6349,3970,751,5997,6114,9903,3859,6900,7722,2378,1996,8902,228,4461,90,7321,7893,4879,9987,1146,8177,1073,7254,5088,402,4266,6443,3084,1403,5357,2565,3470,3639,9468,8932,3119,5839,8008,2712,2735,825,4236,3703,2711,530,9630,1521,2174,5027,4833,3483,445,8300,3194,8784,279,3097,1491,9864,4992,6164,2043,5364,9192,9649,9944,7230,7224,585,3722,5628,4833,8379,3967,5649,2554,5828,4331,3547,7847,5433,3394,4968,9983,3540,9224,6216,9665,8070,31,3555,4198,2626,9553,9724,4503,1951,9980,3975,6025,8928,2952,911,3674,6620,3745,6548,4985,5206,5777,1908,6029,2322,2626,2188,5639]
565610


*/