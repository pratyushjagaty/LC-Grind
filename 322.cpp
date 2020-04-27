// https://leetcode.com/problems/coin-change/submissions/

class Solution {
    int dp[100005];
    
public:
    int f(vector<int>& coins, int amount) {
        if (!amount) {
            return 0;
        }
        
        if (dp[amount] != -1) {
            return dp[amount];
        }
        
        int ans = 1000000;
        
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                ans = min(ans, 1 + f(coins, amount - coins[i]));
            }
        }
        
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = f(coins, amount);
        return (ans != 1000000 ? ans : -1);
    }
};