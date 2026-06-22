class Solution {
public:
    int costs(int n, vector<int>& cost, vector<int>& dp) {
        if (n == 0 || n == 1) return 0;
        if (dp[n] != -1) return dp[n];
        int os = costs(n - 1, cost, dp) + cost[n - 1];
        int ts = INT_MAX;
        if (n > 1) ts = costs(n - 2, cost, dp) + cost[n - 2];
        return dp[n] = min(os, ts);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return costs(n, cost, dp);
    }
};
