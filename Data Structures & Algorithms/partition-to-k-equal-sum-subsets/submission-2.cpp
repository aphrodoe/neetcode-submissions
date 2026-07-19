class Solution {
public:
    bool check(vector<int>& nums, int s, vector<int>& sums, int ind) {
        if (ind == nums.size()) return true;
        for (int i = 0; i < sums.size(); i++) {
            sums[i] += nums[ind];
            if (sums[i] > s) {
                sums[i] -= nums[ind];
                continue;
            }
            if (check(nums, s, sums, ind + 1)) return true;
            sums[i] -= nums[ind];
            if (sums[i] == 0) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        vector<int> sums(k, 0);
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > sum / k) return false;
        return check(nums, sum / k, sums, 0);
    }
};