class Solution {
public:
    bool generate(vector<vector<char>>& board, string word, int r, int c, int n, vector<vector<int>>& visited) {
        if (n == word.size()) return true;

        char nextc = word[n];
        visited[r][c] = 1;

        if (r - 1 >= 0 && board[r - 1][c] == nextc && visited[r - 1][c] == 0) {
            if (generate(board, word, r - 1, c, n + 1, visited)) return true;
            else visited[r - 1][c] = 0;
        }
        if (r + 1 < board.size() && board[r + 1][c] == nextc && visited[r + 1][c] == 0) {
            if (generate(board, word, r + 1, c, n + 1, visited)) return true;
            else visited[r + 1][c] = 0;
        }
        if (c - 1 >= 0 && board[r][c - 1] == nextc && visited[r][c - 1] == 0) {
            if (generate(board, word, r, c - 1, n + 1, visited)) return true;
            else visited[r][c - 1] = 0;
        }
        if (c + 1 < board[0].size() && board[r][c + 1] == nextc && visited[r][c + 1] == 0) {
            if (generate(board, word, r, c + 1, n + 1, visited)) return true;
            else visited[r][c + 1] = 0;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool flag = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, 0));
                    flag = generate(board, word, i, j, 1, visited);
                    if (flag) return flag;
                }
            }
        }

        return flag;
    }
};