class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 || k == 0) return false;
        int i = 0, j = 1;
        while (j < n) {
            if (j - i > k) {
                i++;
                j = i + 1;
            }
            if (nums[i] == nums[j]) return true;
            j++;
        }
        return false;
    }
};