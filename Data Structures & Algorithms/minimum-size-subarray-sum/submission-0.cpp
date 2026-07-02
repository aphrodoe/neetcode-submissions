class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 1e9, n = nums.size();
        int i = 0, j = 0, sum = 0;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                len = min(len, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (len == 1e9) ? 0 : len;
    }
};