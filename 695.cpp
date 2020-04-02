// https://leetcode.com/problems/max-area-of-island/

class Solution {
    int vis[55][55];
    int ans, m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    void dfs(int i, int j, int& cnt, vector<vector<int>>& grid) {
        if (i < 0 or i >= m or j < 0 or j >= n) {
            return;
        }    
        if (!grid[i][j] or vis[i][j]) {
            return;
        }
        
        vis[i][j] = 1;
        cnt++;
        
        for (int it = 0; it < 4; it++) {
            int nx = i + dx[it];
            int ny = j + dy[it];
            dfs(nx, ny, cnt, grid);
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans = 0;
        m = grid.size(), n = grid[0].size();
        memset(vis, 0, sizeof(vis));
        
        //begin dfs
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int cnt = 0;
                    dfs(i, j, cnt, grid);
                    ans = max(ans, cnt);
                }
            }
        }
        
        return ans;
    }
};