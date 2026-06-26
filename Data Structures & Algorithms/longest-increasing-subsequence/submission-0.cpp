class Solution {
public:
    int len(int ind, int last, vector<int>& nums, vector<unordered_map<int, int>>& dp) {
        if (ind == 0) {
            if (nums[0] < last) return 1;
            else return 0;
        }
        if (dp[ind].find(last) != dp[ind].end()) return dp[ind][last];
        int notpick = len(ind - 1, last, nums, dp);
        int pick = INT_MIN;
        if (nums[ind] < last) pick = 1 + len(ind - 1, nums[ind], nums, dp);
        return dp[ind][last] = max(notpick, pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        return len(n - 1, INT_MAX, nums, dp);
    }
};
