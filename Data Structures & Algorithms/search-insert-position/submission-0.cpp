class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int lb = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                lb = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return (lb == -1) ? nums.size() : lb;
    }
};