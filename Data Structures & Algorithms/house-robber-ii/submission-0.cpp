class Solution {
public:
    int robh(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0) return nums[ind];
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + robh(ind - 2, nums, dp);
        int notpick = robh(ind - 1, nums, dp);
        return dp[ind] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, -1);
        int l1 = robh(n - 2, nums, dp);
        vector<int> nums2(nums.begin() + 1, nums.end());
        for (int i = 0; i < n; i++) dp[i] = -1;
        int l2 = robh(n - 2, nums2, dp);
        return max(l1, l2);
    }
};