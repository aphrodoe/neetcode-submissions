class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
        vector<int> ans;

        while (l <= r && u <= d) {
            for (int i = l; i <= r; i++) ans.push_back(matrix[u][i]);
            u++;
            for (int i = u; i <= d; i++) ans.push_back(matrix[i][r]);
            r--;
            if (!(l <= r && u <= d)) break;
            for (int i = r; i >= l; i--) ans.push_back(matrix[d][i]);
            d--;
            for (int i = d; i >= u; i--) ans.push_back(matrix[i][l]);
            l++;
        }

        return ans;
    }
};
