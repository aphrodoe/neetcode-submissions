class Solution {
public:
    int bfs(vector<vector<int>> grid, int r, int c, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        int area = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = it.first + drow[i];
                int nc = it.second + dcol[i];
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
                    if (grid[nr][nc] == 1 && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        area++;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxa = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vis[i][j] = 1;
                    maxa = max(maxa, bfs(grid, i, j, vis));
                }
            }
        }
        return maxa;
    }
};
