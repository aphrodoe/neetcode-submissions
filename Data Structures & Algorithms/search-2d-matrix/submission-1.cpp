class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ir = 0, jr = matrix.size() - 1;
        int r = -1;
        int s = matrix[0].size() - 1;
        while (ir <= jr) {
            int mid = ir + (jr - ir) / 2;
            if (matrix[mid][0] <= target && matrix[mid][s] >= target) {
                r = mid;
                break;
            }
            else if (matrix[mid][0] > target) jr = mid - 1;
            else ir = mid + 1;
        }
        if (r == -1) return false;
        int ic = 0, jc = s;
        while (ic <= jc) {
            int mid = ic + (jc - ic) / 2;
            if (matrix[r][mid] == target) return true;
            else if (matrix[r][mid] > target) jc = mid - 1;
            else ic = mid + 1;
        }
        return false;
    }
};
