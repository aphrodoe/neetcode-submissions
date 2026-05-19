class Solution {
public:

    int boxnum(int i, int j) {
        if (i >= 0 && i <= 2 && j >= 0 && j <= 2) return 0;
        else if (i >= 0 && i <= 2 && j >= 3 && j <= 5) return 1;
        else if (i >= 0 && i <= 2 && j >= 6 && j <= 8) return 2;
        else if (i >= 3 && i <= 5 && j >= 0 && j <= 2) return 3;
        else if (i >= 3 && i <= 5 && j >= 3 && j <= 5) return 4;
        else if (i >= 3 && i <= 5 && j >= 6 && j <= 8) return 5;
        else if (i >= 6 && i <= 8 && j >= 0 && j <= 2) return 6;
        else if (i >= 6 && i <= 8 && j >= 3 && j <= 5) return 7;
        else if (i >= 6 && i <= 8 && j >= 6 && j <= 8) return 8;
        return 0;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>> rhash(n, vector<int>(n, 0));
        vector<vector<int>> chash(n, vector<int>(n, 0));
        vector<vector<int>> bhash(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                if (rhash[i][val] != 0) return false;
                if (rhash[i][val] == 0) rhash[i][val] = 1;
                if (chash[j][val] != 0) return false;
                if (chash[j][val] == 0) chash[j][val] = 1;
                if (bhash[boxnum(i, j)][val] != 0) return false;
                if (bhash[boxnum(i, j)][val] == 0) bhash[boxnum(i, j)][val] = 1;
            }
        }
        return true;

    }
};
