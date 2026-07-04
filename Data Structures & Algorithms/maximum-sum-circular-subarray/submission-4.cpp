class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = -1e9, minsum = 1e9, currmax = 0, currmin = 0, n = nums.size(), total = 0;
        for (int i = 0; i < n; i++) {
            currmax = max(nums[i], currmax + nums[i]);
            currmin = min(nums[i], currmin + nums[i]);
            maxsum = max(maxsum, currmax);
            minsum = min(minsum, currmin);
            total += nums[i];
        }
        return (maxsum >= 0) ? max(maxsum, total - minsum) : maxsum;
    }
};