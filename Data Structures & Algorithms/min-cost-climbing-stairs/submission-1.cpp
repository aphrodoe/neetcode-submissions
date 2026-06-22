class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int os = dp[i - 1] + cost[i - 1];
            int ts = INT_MAX;
            if (n > 1) ts = dp[i - 2] + cost[i - 2];
            dp[i] = min(os, ts);
        }
        return dp[n];
    }
};
