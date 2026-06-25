class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int a = 0; a <= amount; a++) {
            if (a % coins[0] == 0) dp[0][a] = 1;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int a = 0; a <= amount; a++) {
                int nottake = dp[ind - 1][a];
                int take = 0;
                if (coins[ind] <= a) take = dp[ind][a - coins[ind]];
                dp[ind][a] = nottake + take;
            }
        }
        return dp[n - 1][amount];
    }
};