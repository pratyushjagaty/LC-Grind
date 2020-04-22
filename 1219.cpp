https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
    int ans = 0;
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
public:
    void dfs(int x, int y, int sum, vector<vector<int>>& grid) {
        if (x < 0 or x >= m or y < 0 or y >= n) {
            return;
        }    
        
        if (!grid[x][y]) {
            return;
        }
        
        ans = max(ans, sum + grid[x][y]);
        int val = grid[x][y];
        grid[x][y] = 0;
        
        for (int i = 0; i < 4; i++) {
            int p = x + dx[i];
            int q = y + dy[i];
            dfs(p, q, sum + val, grid);
        }
        
        grid[x][y] = val;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) { 
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dfs(i, j, 0, grid);
                }
            }
        }
        return ans;
    }
};