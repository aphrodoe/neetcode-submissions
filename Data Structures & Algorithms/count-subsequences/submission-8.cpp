class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                int nottake = prev[j];
                int take = 0;
                if (s[i - 1] == t[j - 1]) take = prev[j - 1];
                prev[j] = nottake + take;
            }
        }

        return prev[m];
    }
};