class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][stones[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= sum; target++) {
                bool take = false;
                if (stones[ind] <= target) take = dp[ind - 1][target - stones[ind]];
                bool nottake = dp[ind - 1][target]; 
                dp[ind][target] = (take | nottake);
            }
        }

        int mind = sum;
        for (int target = 0; target <= sum; target++) {
            if (dp[n - 1][target]) {
                int diff = abs(target - (sum - target));
                mind = min(mind, diff);
            }
        }
        return mind;
    }
};