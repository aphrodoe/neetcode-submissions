class Solution {
public:
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};

    bool dfs(vector<vector<char>>& board, int r, int c, string& target, int index, 
    vector<vector<int>>& vis) {
        if (index == target.size()) return true;
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                if (board[nr][nc] == target[index] && !vis[nr][nc]) {
                    if (dfs(board, nr, nc, target, index + 1, vis)) {
                        vis[r][c] = 0;
                        return true;
                    }
                }
            }
        }
        vis[r][c] = 0;
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool flag;
        for (string word : words) {
            flag = false;
            char start = word[0];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == start && dfs(board, i, j, word, 1, vis)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) continue;
            }
            if (flag) ans.push_back(word);
        }
        return ans;
    }
};
