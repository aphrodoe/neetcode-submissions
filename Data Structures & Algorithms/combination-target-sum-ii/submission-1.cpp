class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& curr, int index, vector<int>& candidates, int sum, int target) {
        if (index == candidates.size()) {
            if (sum == target) ans.push_back(curr);
            return;
        }
        if (sum >= target) {
            if (sum == target) ans.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            sum += candidates[i];
            curr.push_back(candidates[i]);
            generate(ans, curr, i + 1, candidates, sum, target);
            sum -= candidates[i];
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());

        generate(ans, curr, 0, candidates, 0, target);

        return ans;
    }
};