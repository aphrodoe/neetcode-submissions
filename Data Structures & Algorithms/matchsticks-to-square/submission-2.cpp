class Solution {
public:
    bool check(vector<int>& matchsticks, vector<int>& dp, int k, int mask, int sum, int n) {
        if (mask == (1 << n) - 1) return true;
        if (dp[mask] != -1) return dp[mask];
        for (int i = 0; i < matchsticks.size(); i++) {
            if ((mask & (1 << i)) == 0) {
                if (sum + matchsticks[i] <= k) {
                    int nsum = (sum + matchsticks[i]) % k;
                    int nmask = (mask | (1 << i));
                    if (check(matchsticks, dp, k, nmask, nsum, n)) return dp[mask] = 1;
                }
            }
        }
        return dp[mask] = 0;
    }

    bool makesquare(vector<int>& matchsticks) {
        int s = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (s % 4 != 0) return false;
        int k = s / 4;
        int n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        return check(matchsticks, dp, k, 0, 0, n);
    }
};