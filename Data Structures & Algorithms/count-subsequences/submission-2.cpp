class Solution {
public:
    int cnt(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j < 0) return 1;
        if (i < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int nottake = cnt(i - 1, j, s, t, dp);
        int take = 0;
        if (s[i] == t[j]) take = cnt(i - 1, j - 1, s, t, dp);
        return dp[i][j] = nottake + take;
    } 

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, - 1));
        return cnt(n - 1, m - 1, s, t, dp);
    }
};