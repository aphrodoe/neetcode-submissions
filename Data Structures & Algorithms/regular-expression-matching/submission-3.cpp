class Solution {
public:
    bool check(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 &&  j >= 0) {
            if (j == 0) return false;
            for (int k = 1; k <= j; k += 2) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '.') return dp[i][j] = check(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*') {
            bool empty = check(i, j - 2, s, p, dp);
            bool use;
            if (p[j - 1] == '.') use = check(i - 1, j, s, p, dp);
            else if (p[j - 1] == s[i]) use = check(i - 1, j, s, p, dp);
            else use = false;
            if (empty | use) return dp[i][j] = true;

        }
        return dp[i][j] = false;

    } 

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return check(n - 1, m - 1, s, p, dp);
    }
};