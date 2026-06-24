class Solution {
public:
    int get(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (amount == 0) return 0;
            else if (coins[ind] > amount) return 1e9;
        }
        if (amount == 0) return 0;
        if (dp[ind][amount] != -1) return dp[ind][amount];
        int notpick = 1e9;
        if (ind > 0) notpick = 0 + get(ind - 1, amount, coins, dp);
        int pick = 1e9;
        if (coins[ind] <= amount) pick = 1 + get(ind, amount - coins[ind], coins, dp);
        return dp[ind][amount] = min(pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int minc = get(n - 1, amount, coins, dp);
        return (minc == 1e9) ? -1 : minc;
    }
};