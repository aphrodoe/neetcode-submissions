class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int l = low, r = high;
        while (l < r) {
            while (nums[l] <= pivot && l < high) l++;
            while (nums[r] > pivot && r > low) r--;
            if (l < r) swap(nums[l], nums[r]);
        }
        swap(nums[low], nums[r]);
        return r;
    }

    void qs(vector<int>& nums, int low, int high) {
        if (low < high) {
            int par = partition(nums, low, high);
            qs(nums, low, par - 1);
            qs(nums, par + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};