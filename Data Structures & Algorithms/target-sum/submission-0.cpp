class Solution {
public:
    int cnt(int ind, int target, vector<int>& nums, vector<unordered_map<int, int>>& dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            else if (nums[0] == target || nums[0] == -target) return 1;
            else return 0;
        }
        if (dp[ind].find(target) != dp[ind].end()) return dp[ind][target];
        int pos = cnt(ind - 1, target - nums[ind], nums, dp);
        int neg = cnt(ind - 1, target + nums[ind], nums, dp);
        return dp[ind][target] = pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        return cnt(n - 1, target, nums, dp);
    }
};