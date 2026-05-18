class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prep(nums.size(), 1);
        vector<int> postp(nums.size(), 1);
        int pre = 1, post = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            pre *= nums[i];
            prep[i + 1] = pre;
            post *= nums[nums.size() - i - 1];
            postp[nums.size() - i - 2] = post;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(prep[i] * postp[i]);
        }
        return ans;
    }
};
