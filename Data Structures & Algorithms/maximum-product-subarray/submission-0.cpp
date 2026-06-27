class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax = 1, currmin = 1;
        int maxp = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int temp = currmax * nums[i];
            currmax = max(nums[i], max(temp, currmin * nums[i]));
            currmin = min(nums[i], min(temp, currmin * nums[i]));
            maxp = max(maxp, currmax);
        }
        return maxp;
    }
};
