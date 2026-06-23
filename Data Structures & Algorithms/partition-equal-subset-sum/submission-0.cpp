class Solution {
public:
    bool check(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return (nums[0] == target);
        if (dp[ind][target] != -1) return dp[ind][target];
        bool ntake = check(ind - 1, target, nums, dp);
        bool take = false;
        if (target >= nums[ind]) take = check(ind - 1, target - nums[ind], nums, dp);
        return dp[ind][target] = (ntake | take);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        vector<vector<int>> dp(201, vector<int>(20001, -1));
        return check(n - 1, sum / 2, nums, dp);
    }
};