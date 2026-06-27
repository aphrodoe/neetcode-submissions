class Solution {
public:
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};

    int dfs(int r, int c, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp) {
        if (dp[r][c] != -1) return dp[r][c];
        int maxl = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (matrix[nr][nc] > matrix[r][c]) {
                    maxl = max(maxl, 1 + dfs(nr, nc, matrix, n, m, dp));
                }
            }
        }
        return dp[r][c] = maxl;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int lis = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lis = max(lis, dfs(i, j, matrix, n, m, dp));
            }
        }

        return lis;
    }
};
