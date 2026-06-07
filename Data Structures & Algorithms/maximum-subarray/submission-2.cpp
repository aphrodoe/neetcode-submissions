class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxe = INT_MIN, msum = INT_MIN;
        bool pos = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) pos = true;
            sum += nums[i];
            msum = max(msum, sum);
            maxe = max(maxe, nums[i]);
            if (sum < 0) sum = 0;
        }
        return (pos) ? msum : maxe;
    }
};
