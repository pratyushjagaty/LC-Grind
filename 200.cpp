// https://leetcode.com/problems/number-of-islands/

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int vis[1000][1000];
    int m, n;
    int ans;
public:
    
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (x < 0 or x >= m or y < 0 or y >= n) {
            return;
        }    
        
        if (vis[x][y]) {
            return;
        }
        
        if (grid[x][y] == '0') {
            return;
        }
        
        vis[x][y] = 1;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx, ny, grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
        
        if (grid.size() == 0) {
            return ans;
        }
        
        m = grid.size();
        n = grid[0].size();
        memset(vis, 0, sizeof(vis));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' and !vis[i][j]) {
                    ans++;
                    dfs(i, j, grid);
                }    
            }
        }
        
        return ans;
    }
};