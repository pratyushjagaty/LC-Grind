class Solution {
    int dp[100005][2];
    
public:
    // sell -> 0
    // buy -> 1
    int f(int idx, int trade, vector<int>& prices) {
        if (idx >= prices.size()) {
            return 0;
        }
        
        if (dp[idx][trade] != -1) {
            return dp[idx][trade];
        }
        
        int ans = 0;

        if (trade) {
            ans = max(ans, -prices[idx] + f(idx + 1, 0, prices));
            ans = max(ans, f(idx + 1, 1, prices));
        } else {
            ans = max(ans, prices[idx] + f(idx + 1, 1, prices));
            ans = max(ans, f(idx + 1, 0, prices));
        }
        
        return dp[idx][trade] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp)); 
        int ans = f(0, 1, prices);
        return ans;
    }
};