class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mindex = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i <= mindex) {
                mindex = max(mindex, i + nums[i]);
            }
        }
        if (mindex >= nums.size() - 1) return true;
        else return false;
    }
};