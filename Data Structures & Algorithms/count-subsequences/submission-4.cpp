class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = 1;
        curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int nottake = prev[j];
                int take = 0;
                if (s[i - 1] == t[j - 1]) take = prev[j - 1];
                curr[j] = nottake + take;
            }
            prev = curr;
        }

        return prev[m];
    }
};