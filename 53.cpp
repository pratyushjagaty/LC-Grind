// https://leetcode.com/problems/maximum-subarray/
// Kadane's Algorithm


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur + nums[i] < 0) {
                ans = max(ans, cur + nums[i]);
                cur = 0;
            } else {
                cur += nums[i];
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};