class NumMatrix {
private:
    vector<int> pre;
    int n, m;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        pre.resize(m * n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += matrix[i][j];
                int ind = i * m + j;
                pre[ind] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            int l = (r * m + col1 - 1 >= 0) ? pre[r * m + col1 - 1] : 0;
            sum += pre[r * m + col2] - l;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */