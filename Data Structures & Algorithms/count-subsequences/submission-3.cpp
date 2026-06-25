class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int j = 0; j <= m; j++) dp[0][j] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int nottake = dp[i - 1][j];
                int take = 0;
                if (s[i - 1] == t[j - 1]) take = dp[i - 1][j - 1];
                dp[i][j] = nottake + take;
            }
        }

        return dp[n][m];
    }
};