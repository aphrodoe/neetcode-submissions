class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = it.second.first + drow[i];
                int nc = it.second.second + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (grid[nr][nc] == INT_MAX && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        grid[nr][nc] = it.first + 1;
                        q.push({it.first + 1, {nr, nc}});
                    }
                }
            }
        }
    }
};
