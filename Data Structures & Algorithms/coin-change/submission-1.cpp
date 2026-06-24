class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1);
        for (int a = 0; a <= amount; a++) {
            if (a % coins[0] == 0) prev[a] = a / coins[0];
            else prev[a] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int a = 0; a <= amount; a++) {
                int notpick = prev[a];
                int pick = 1e9;
                if (coins[ind] <= a) pick = 1 + prev[a - coins[ind]];
                prev[a] = min(pick, notpick);
            }
        }

        int ans = prev[amount];
        return (ans == 1e9) ? -1 : ans;
    }
};