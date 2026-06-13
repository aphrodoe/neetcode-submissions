class Solution {
public:
    void generate(int index, int target, vector<int>& curr, vector<vector<int>>& ans, int sum, vector<int>& candidates) {
        // base cases
        if (index == candidates.size()) {
            if (sum == target) ans.push_back(curr);
            return;
        }
        if (sum >= target) {
            if (sum == target) ans.push_back(curr);
            return;
        }

        // repeat pick
        sum += candidates[index];
        curr.push_back(candidates[index]);
        generate(index, target, curr, ans, sum, candidates);

        // backtrack
        sum -= candidates[index];
        curr.pop_back();

        // do not pick
        generate(index + 1, target, curr, ans, sum, candidates);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        generate(0, target, curr, ans, 0, candidates);

        return ans;
    }
};