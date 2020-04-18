// https://leetcode.com/problems/minimum-path-sum/

class Solution {
    int dp[1001][1001];
    int m, n;
public:
    int f(int x, int y, vector<vector<int>>& grid) {
        if (x == m - 1 and y == n - 1) {
            return grid[x][y];
        }
        
        if (x >= m or y >= n) {
            return 100000000;
        }
        
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        int ans = INT_MAX;
        ans = min(ans, grid[x][y] + f(x + 1, y, grid));
        ans = min(ans, grid[x][y] + f(x, y + 1, grid));
        
        return dp[x][y] = ans;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        m = grid.size();
        n = grid[0].size();
        
        return f(0, 0, grid);
    }
};