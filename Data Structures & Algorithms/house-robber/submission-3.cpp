class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        int prev1 = nums[0], prev2 = 0, curr;
        if (n == 0) return prev1;
        for (int i = 1; i <= n; i++) {
            int pick = nums[i] + prev2;
            int notpick = prev1;
            curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};