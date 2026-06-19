class Solution {
public:
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int r, int c, int n, int m) {
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (board[nr][nc] == 'O') {
                    board[nr][nc] = 'S';
                    dfs(board, nr, nc, n, m);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'S';
                dfs(board, i, 0, n, m);
            }
            if (board[i][m - 1] == 'O') {
                board[i][m - 1] = 'S';
                dfs(board, i, m - 1, n, m);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = 'S';
                dfs(board, 0, i, n, m);
            }
            if (board[n - 1][i] == 'O') {
                board[n - 1][i] = 'S';
                dfs(board, n - 1, i, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};
