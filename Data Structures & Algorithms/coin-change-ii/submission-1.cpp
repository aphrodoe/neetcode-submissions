class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int a = 0; a <= amount; a++) {
            if (a % coins[0] == 0) prev[a] = 1;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int a = 0; a <= amount; a++) {
                int nottake = prev[a];
                int take = 0;
                if (coins[ind] <= a) take = prev[a - coins[ind]];
                prev[a] = nottake + take;
            }
        }
        return prev[amount];
    }
};