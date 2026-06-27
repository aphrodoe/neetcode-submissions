class Solution {
public:
    int cnt(int i, string& s, vector<int>& dp) {
        if (s[i] == '0') return 0;
        if (i == s.size()) return 0;
        if (i == s.size() - 1) return 1;
        if (dp[i] != -1) return dp[i];
        int ways = 0, curr = 0;
        for (int j = i; j < i + 2; j++) {
            int dig = s[j] - '0';
            curr = (curr * 10) + dig;
            if (curr >= 1 && curr <= 26) {
                if (j + 1 < s.size()) ways += cnt(j + 1, s, dp);
                else ways++;
            }
        }
        return dp[i] = ways;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return cnt(0, s, dp);
    }
};
