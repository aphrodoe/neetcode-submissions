class Solution {
public:
    int cnt(int r, int c, vector<vector<int>>& dp) {
        if (r == 0 && c == 0) return 1;
        if (dp[r][c] != -1) return dp[r][c];
        int ways = 0;
        if (r > 0) ways += cnt(r - 1, c, dp);
        if (c > 0) ways += cnt(r, c - 1, dp);
        return dp[r][c] = ways;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return cnt(m - 1, n - 1, dp);
    }
};