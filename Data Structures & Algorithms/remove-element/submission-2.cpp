class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        bool flag = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                flag = false;
                break;
            }
        }

        if (flag) return 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (nums[j] == val && i < j) j--;
            while (nums[i] != val && i < j) i++;
            swap(nums[i], nums[j]);
        }

        return j + 1;
    }
};