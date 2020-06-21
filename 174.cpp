class Solution {
    int rows, cols;
    int dp[505][505];
    
public:
    int f(int x, int y, vector<vector<int>>& dungeon) {
        
        if (x == rows or y == cols) {
            return INT_MAX;
        }
        
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        int next = min(f(x + 1, y, dungeon), f(x, y + 1, dungeon));
        
        if (next == INT_MAX) {
            next = 1;
        }
        
        int res = max(next - dungeon[x][y], 1);
        
        return dp[x][y] = res;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size(), cols = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, dungeon);
    }
};