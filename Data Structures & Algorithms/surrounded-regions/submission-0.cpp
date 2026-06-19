class Solution {
public:
    void is_safe(vector<vector<char>>& board, int r, int c, vector<vector<int>>& vis, int n, int m, bool& flag, vector<int>& drow, vector<int>& dcol) {
        queue<pair<int, int>> q;
        q.push({r, c});

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) flag = true;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = it.first + drow[i];
                int nc = it.second + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (board[nr][nc] == 'O' && !vis[nr][nc] && (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1)) {
                        flag = true;
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                    else if (board[nr][nc] == 'O' && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    void mark(vector<vector<char>>& board, vector<vector<bool>>& safe, int r, int c, vector<vector<int>>& vis, int n, int m, vector<int>& drow, vector<int>& dcol) {
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (board[nr][nc] == 'O' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    safe[nr][nc] = true;
                    mark(board, safe, nr, nc, vis, n, m, drow, dcol);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> safe(n, vector<bool>(m, false));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> vism(n, vector<int>(m, 0));
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    vis[i][j] = 1;
                    bool flag = false;
                    is_safe(board, i, j, vis, n, m, flag, drow, dcol);
                    if (flag) {
                        vism[i][j] = 1;
                        safe[i][j] = true;
                        mark(board, safe, i, j, vism, n, m, drow, dcol);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !safe[i][j]) board[i][j] = 'X';
            }
        }
    }
};
