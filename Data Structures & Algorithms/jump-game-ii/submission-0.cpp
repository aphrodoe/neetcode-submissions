class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> minjumps(n, INT_MAX);
        minjumps[0] = 0;
        for (int i = 0; i < n; i++) {
            int currj = minjumps[i];
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < nums.size()) minjumps[i + j] = min(minjumps[i + j], currj + 1);
            }
        }
        return minjumps[n - 1];
    }
};