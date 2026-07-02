class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && nums[i] == nums[j]) j++;
            if (i + 1 < n && j < n) nums[i + 1] = nums[j];
            i++;
        }
        return i;
    }
};