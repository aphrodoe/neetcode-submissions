class Solution {
public:
    void generate(vector<int>& nums, set<vector<int>>& s, vector<int>& curr, int n) {
        if (curr.size() == n) s.insert(curr);
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            curr.push_back(num);
            nums.erase(nums.begin() + i);
            generate(nums, s, curr, n);
            nums.insert(nums.begin() + i, num);
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> curr;
        int n = nums.size();
        generate(nums, s, curr, n);
        vector<vector<int>> ans;
        for (auto& it : s) ans.push_back(it);
        return ans;
    }
};