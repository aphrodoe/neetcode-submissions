class Solution {
public:
    int cnt(int sum, vector<int>& dp) {
        if (sum < 0) return INT_MAX;
        if (sum == 0) return 0;
        if (dp[sum] != -1) return dp[sum];
        int mins = INT_MAX;
        for (int i = 1; i <= sqrt(sum); i++) {
            int pick = 1 + cnt(sum - i * i, dp);
            mins = min(mins, pick);
        }
        return dp[sum] = mins;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return cnt(n, dp);
    }
};