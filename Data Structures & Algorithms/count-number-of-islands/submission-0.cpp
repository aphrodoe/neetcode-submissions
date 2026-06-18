class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            grid[r][c] = '0';
            for (int i = 0; i < 4; i++) {
                int rn = r + drow[i];
                int rc = c + dcol[i];
                if (rn >= 0 && rn < grid.size() && rc >= 0 && rc < grid[0].size()) {
                    if (grid[rn][rc] == '1') q.push({rn, rc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    bfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};
