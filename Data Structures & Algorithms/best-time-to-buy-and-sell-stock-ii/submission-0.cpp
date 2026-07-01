class Solution {
public:
    int profit(int i, int b, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size() - 1) {
            if (b == 0) return 0;
            else return prices[i];
        }
        if (dp[i][b] != -1) return dp[i][b];
        int buy = INT_MIN, sell = INT_MIN, nothing = profit(i + 1, b, prices, dp);
        if (b == 0) buy = -prices[i] + profit(i + 1, 1, prices, dp);
        if (b == 1) sell = prices[i] + profit(i + 1, 0, prices, dp);

        return dp[i][b] = max(nothing, max(buy, sell));
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return profit(0, 0, prices, dp);
    }
};