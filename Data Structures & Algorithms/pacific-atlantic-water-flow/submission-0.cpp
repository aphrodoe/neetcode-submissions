class Solution {
public:
    class PairHash {
    public:
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second); 
        }
    };

    void dfs(vector<vector<int>>& heights, int r, int c, vector<int>& drow, vector<int>& dcol,
    int n, int m, unordered_map<pair<int, int>, int, PairHash>& mp) {
        mp[{r, c}] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (heights[nr][nc] >= heights[r][c] && mp.find({nr, nc}) == mp.end()) {
                    dfs(heights, nr, nc, drow, dcol, n, m, mp);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        unordered_map<pair<int, int>, int, PairHash> pmap;
        unordered_map<pair<int, int>, int, PairHash> amap;

        for (int i = 0; i < m; i++) dfs(heights, 0, i, drow, dcol, n, m, pmap);
        for (int i = 0; i < n; i++) dfs(heights, i, 0, drow, dcol, n, m, pmap);
        for (int i = 0; i < m; i++) dfs(heights, n - 1, i, drow, dcol, n, m, amap);
        for (int i = 0; i < n; i++) dfs(heights, i, m - 1, drow, dcol, n, m, amap);

        vector<vector<int>> ans;
        for (auto it: pmap) {
            if (amap.find(it.first) != amap.end()) ans.push_back({it.first.first, it.first.second});
        }

        return ans;
    }
};
