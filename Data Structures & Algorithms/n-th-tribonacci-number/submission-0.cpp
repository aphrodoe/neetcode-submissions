class Solution {
public:
    int tribonacci(int n) {
        vector<int> tri = {0, 1, 1};
        if (n < 3) return tri[n];
        for (int i = 0; i < n - 2; i++) {
            int val = tri[0] + tri[1] + tri[2];
            tri[0] = tri[1];
            tri[1] = tri[2];
            tri[2] = val;
        }
        return tri[2];
    }
};