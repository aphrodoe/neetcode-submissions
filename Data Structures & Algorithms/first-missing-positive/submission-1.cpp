class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) nums[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            int ind;
            if (nums[i] < 0 && nums[i] >= -n) ind = -1 * nums[i] - 1;
            else if (nums[i] > 0 && nums[i] <= n) ind = nums[i] - 1;
            else continue;

            if (nums[ind] < 0) continue;
            else if (nums[ind] > 0) nums[ind] *= -1;
            else nums[ind] = INT_MIN;  
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) return i + 1;
        }

        return n + 1;
    }
};