class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int index, int cnt) {
        if (cnt == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            generate(ans, curr, nums, i + 1, cnt - 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size(); i++) {
            generate(ans, curr, nums, 0, i);
            curr.clear();
        }

        return ans;
    }
};