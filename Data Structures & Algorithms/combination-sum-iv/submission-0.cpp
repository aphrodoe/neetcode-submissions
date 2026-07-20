class Solution {
public:
    int cnt(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;
        int ways = 0;
        if (dp[target] != -1) return dp[target];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= target) ways += cnt(nums, target - nums[i], dp);
        }
        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1001, -1);
        return cnt(nums, target, dp);
    }
};