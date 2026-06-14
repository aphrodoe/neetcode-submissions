class Solution {
public:
    void place(vector<vector<string>>& ans, vector<string>& board, int n, int row, vector<int>& col, vector<int>& d1, vector<int>& d2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col[i] == 0 && d1[row + i] == 0 && d2[row - i + n] == 0) {
                col[i] = 1;
                d1[row + i] = 1;
                d2[row - i + n] = 1;
                board[row][i] = 'Q';
                place(ans, board, n, row + 1, col, d1, d2);
                col[i] = 0;
                d1[row + i] = 0;
                d2[row - i + n] = 0;
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string row(n, '.');
        for (int i = 0; i < n; i++) board.push_back(row);
        vector<int> col(n, 0);
        vector<int> d1(2 * n, 0);
        vector<int> d2(2 * n, 0);

        place(ans, board, n, 0, col, d1, d2);

        return ans;
    }
};