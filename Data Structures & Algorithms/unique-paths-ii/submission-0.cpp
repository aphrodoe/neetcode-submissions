class Solution {
public:
    int cnt(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r == 0 && c == 0) return 1;
        if (grid[r][c] == 1) return 0;
        if (dp[r][c] != -1) return dp[r][c];
        int up = 0, left = 0;
        if (r > 0) up = cnt(r - 1, c, grid, dp);
        if (c > 0) left = cnt(r, c - 1, grid, dp);
        return dp[r][c] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return cnt(m - 1, n - 1, obstacleGrid, dp);
    }
};