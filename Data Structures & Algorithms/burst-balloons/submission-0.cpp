class Solution {
public:
    int coins(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int maxi = -1e9;
        for (int k = i; k <= j; k++) {
            int gain = nums[i - 1] * nums[k] * nums[j + 1];
            gain += coins(i, k - 1, nums, dp) + coins(k + 1, j, nums, dp);
            maxi = max(maxi, gain);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(1);
        for (int& n : nums) temp.push_back(n);
        temp.push_back(1);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return coins(1, temp.size() - 2, temp, dp);
    }
};