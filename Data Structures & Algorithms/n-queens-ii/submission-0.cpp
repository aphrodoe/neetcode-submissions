class Solution {
public:
    int cnt(int n, int r, vector<int>& col, vector<int>& d1, vector<int>& d2) {
        if (r == n) return 1;
        int s = 0;
        for (int c = 0; c < n; c++) {
            if (col[c] == 0 && d1[r + c] == 0 && d2[r - c + n - 1] == 0) {
                col[c] = 1;
                d1[r + c] = 1;
                d2[r - c + n - 1] = 1;
                s += cnt(n, r + 1, col, d1, d2);
                col[c] = 0;
                d1[r + c] = 0;
                d2[r - c + n - 1] = 0;
            }
        }
        return s;
    }

    int totalNQueens(int n) {
        vector<int> col(n + 1, 0);
        vector<int> d1(2 * n + 1, 0);
        vector<int> d2(2 * n + 1, 0);
        return cnt(n, 0, col, d1, d2);
    }
};