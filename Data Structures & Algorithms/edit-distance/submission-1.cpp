class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1 , -1));
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for (int i = 0; i <= n; i++) dp[i][0] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                int in = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int mini = min(in, del);
                int rep = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(mini, rep);
            }
        }

        return dp[n][m];
    }
};