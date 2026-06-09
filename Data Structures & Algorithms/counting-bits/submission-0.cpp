class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i < n + 1; i++) {
            int res = 0;
            int n = i;
            while (n) {
                n = n & (n - 1);
                res++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
