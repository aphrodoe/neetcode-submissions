class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        int i = 0, j = 0;
        while (j < n) {
            while (j - i > k) {
                s.erase(nums[i]);
                i++;
            }
            if (s.count(nums[j])) return true;
            s.insert(nums[j]);
            j++;
        }

        return false;
    }
};