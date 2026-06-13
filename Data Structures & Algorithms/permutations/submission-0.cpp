class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int n) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            curr.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            generate(ans, curr, nums, n);
            curr.pop_back();
            nums.insert(nums.begin() + i, num);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        generate(ans, curr, nums, nums.size());

        return ans;
    }
};
