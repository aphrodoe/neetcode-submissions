class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({0, {i, j}});
            }
        }

        int maxt = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            maxt = max(maxt, it.first);
            for (int i = 0; i < 4; i++) {
                int nr = it.second.first + drow[i];
                int nc = it.second.second + dcol[i];
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({it.first + 1, {nr, nc}});
                    }
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return maxt;
    }
};
