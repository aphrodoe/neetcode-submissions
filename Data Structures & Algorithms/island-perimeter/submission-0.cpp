class Solution {
public:
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};

    void bfs(int r, int c, vector<vector<int>>& grid, int& p, vector<vector<int>>& vis, int n, int m) {
        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int neigh = 0;
            for (int i = 0; i < 4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    neigh++;
                    if (!vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                } 
            }
            p += 4 - neigh;
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), p = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (flag) break;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    bfs(i, j, grid, p, vis, n, m);
                    flag = true;
                    break;
                }
            }
        }
        return p;
    }
};