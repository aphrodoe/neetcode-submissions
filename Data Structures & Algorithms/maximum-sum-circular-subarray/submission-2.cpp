class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), msum = -1e9;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < i + n; j++) {
                sum += nums[j % n];
                msum = max(msum, sum);
                if (sum < 0) sum = 0;
            }
        }
        return msum;
    }
};