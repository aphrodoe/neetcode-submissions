class Solution {
public:
    int cnt(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (j < 0) return i + 1;
        if (i < 0) return j + 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) return cnt(i - 1, j - 1, word1, word2, dp);
        int in = 1 + cnt(i, j - 1, word1, word2, dp);
        int del = 1 + cnt(i - 1, j, word1, word2, dp);
        int min1 = min(in, del);
        int rep = 1 + cnt(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] = min(min1, rep);

    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m , -1));
        return cnt(n - 1, m - 1, word1, word2, dp);
    }
};