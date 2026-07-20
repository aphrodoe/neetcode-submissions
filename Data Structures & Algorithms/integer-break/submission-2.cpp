class Solution {
public:
    int maxpr(int sum, int first, vector<vector<int>>& dp) {
        if (sum == 0 || sum == 1) return 1; 
        if (dp[sum][first] != -1) return dp[sum][first];
        int maxp = INT_MIN, end;
        if (first) end = sum - 1;
        else end = sum;
        for (int i = 1; i <= end; i++) {
            int p = i * maxpr(sum - i, 0, dp);
            maxp = max(maxp, p);
        }
        return dp[sum][first] = maxp;
    }

    int integerBreak(int n) {
        vector<vector<int>> dp(59, vector<int>(2, -1));
        return maxpr(n, 1, dp);
    }
};