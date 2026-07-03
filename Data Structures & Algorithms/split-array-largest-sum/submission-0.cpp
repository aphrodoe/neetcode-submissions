class Solution {
public:
    bool check(vector<int>& nums, int ls, int k) {
        int sub = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > ls) {
                sub++;
                sum = nums[i];
            }
            if (i == nums.size() - 1) sub++;
        }
        return (sub <= k);
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);
        int ls = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid, k)) {
                ls = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ls;
    }
};