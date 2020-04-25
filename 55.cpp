// https://leetcode.com/problems/jump-game/

class Solution {
    int dp[100005];
public:
    bool canJump(vector<int>& nums) {
        if (nums[0] == 0 and nums.size() == 1) {
            return true;
        }
        
        dp[0] = (nums[0] != 0);
        cout << dp[0] << endl;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i]) {
                for (int j = 1; j <= nums[i]; j++) {
                    if (i + j < nums.size()) {
                        dp[i + j] = 1;
                    }
                }
            }
        }
        return dp[nums.size() - 1];   
    }
};