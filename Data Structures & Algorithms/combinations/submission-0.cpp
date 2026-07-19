class Solution {
public:
    void comb(int i, int n, int k, vector<vector<int>>& ans, vector<int>& curr) {
        if (i == n + 1) {
            if (k == 0) ans.push_back(curr);
            return;
        }
        curr.push_back(i);
        comb(i + 1, n, k - 1, ans, curr);
        curr.pop_back();
        comb(i + 1, n, k, ans, curr);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        comb(1, n, k, ans, curr);
        return ans;
    }
};