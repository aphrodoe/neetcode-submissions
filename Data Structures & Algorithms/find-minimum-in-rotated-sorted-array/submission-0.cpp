class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int mine = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[l] <= nums[mid]) {
                mine = min(mine, nums[l]);
                l = mid + 1;
            }
            else {
                mine = min(mine, nums[mid]);
                r = mid - 1;
            }
        }
        return mine;
    }
};
