class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& curr, int index, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        generate(ans, curr, index + 1, nums);

        curr.pop_back();
        generate(ans, curr, index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        generate(ans, curr, 0, nums);

        return ans;
    }
};
