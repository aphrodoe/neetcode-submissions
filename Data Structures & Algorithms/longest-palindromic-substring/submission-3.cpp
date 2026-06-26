class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        int ms = 0, mi = 0, mj = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j == i + 1) {
                        dp[i][j] = 1;
                    }
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                else dp[i][j] = 0;

                if (dp[i][j] == 1 && j - i + 1 > ms) {
                    ms = j - i + 1;
                    mi = i;
                    mj = j;
                }
            }
        }
        return s.substr(mi, mj - mi + 1);
    }
};
